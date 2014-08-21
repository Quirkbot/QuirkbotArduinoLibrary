#ifndef Wave_h_
#define Wave_h_

#include <Arduino.h>

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"
#include "WaveTables.h"


#define	WAVE_SINE 0
#define	WAVE_SQUARE 1
#define	WAVE_TRIANGLE 2
#define	WAVE_PULSE 3
#define	WAVE_RAMP_UP 4
#define	WAVE_RAMP_DOWN 5

/*
Should we have a bunch of different nodes with an specific wave form, instead of
configuring the wave via the 'type' input? We would get longer and more cryptic
node names, but also would remove the type input (removing inputs is always a 
good thig).

SineWave
SquareWave
TriangleWave
PulseWave
RampUpWave
RampDownWave
*/

class Wave :
public Node,
public HasInterval,
public OutputStream<float>
{
	public:

	Wave():
	HasInterval
		(this),
	OutputStream<float>
		(value){
		registerInput(duration);
		registerInput(offset);
		registerInput(type);

		interval = 0.033;

		position = 0;
		offset = 0.0;
		type = WAVE_SINE;		
		duration = 1.0;
	};

	void onInterval();

	Input<float> duration;
	Input<float> offset;
	Input<float> type;
	
	Output<float> value;

	protected:

	const int16_t * table;
	
	void onInternalInputChange(BaseInput &input);

	float adjust;
	float position;
};

void Wave::onInternalInputChange(BaseInput &input){
	if(&input == &type){
		switch ((int)type){
			case WAVE_SQUARE:
				table = WAVE_SQUARE_TABLE;
				break;
			case WAVE_PULSE:
				table = WAVE_PULSE_TABLE;
				break;
			case WAVE_TRIANGLE:
				table = WAVE_TRIANGLE_TABLE;
				break;
			case WAVE_RAMP_UP:
				table = WAVE_RAMP_UP_TABLE;
				break;
			case WAVE_RAMP_DOWN:
				table = WAVE_RAMP_DOWN_TABLE;
				break;
			case WAVE_SINE:
			default:
				table = WAVE_SINE_TABLE;
				break;
		}
	}
	else if(&input == &duration){
		float basePosition = position - offset;
		if(basePosition < 0) basePosition += 1;

		float currentTime = fmod(Bot::seconds, duration);
		float diff = currentTime/duration - basePosition;
		adjust = diff * duration;
	}
};

void Wave::onInterval(){
	float timeSeconds = fmod(Bot::seconds -adjust + offset * duration, duration);
	position = timeSeconds / duration;
	int index = position * 256.0;
	value = (float)(pgm_read_word_near(table + index)) * 0.001;
}

#endif
