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
#define	WAVE_SQUARE 0.2
#define	WAVE_TRIANGLE 0.4
#define	WAVE_PULSE 0.6
#define	WAVE_RAMP_UP 0.8
#define	WAVE_RAMP_DOWN 1.0

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
		(this){
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

	protected:

	const int16_t * table;
	
	void onInternalInputChange(BaseInput &internalInput);

	float adjust;
	float position;
};

void Wave::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &type){
		float t = type.get();
		if(t <= WAVE_SQUARE){
			table = WAVE_SQUARE_TABLE;
		}
		else if (t <= WAVE_SQUARE){
			table = WAVE_SQUARE_TABLE;
		}
		if (t <= WAVE_PULSE){
			table = WAVE_PULSE_TABLE;
		}
		if (t <= WAVE_TRIANGLE){
			table = WAVE_TRIANGLE_TABLE;
		}
		if (t <= WAVE_RAMP_UP){
			table = WAVE_RAMP_UP_TABLE;
		}
		if (t <= WAVE_RAMP_DOWN){
			table = WAVE_RAMP_DOWN_TABLE;
		}
		if (t <= WAVE_SINE){
			table = WAVE_SINE_TABLE;
		}
	}
	else if(&internalInput == &duration){
		float basePosition = position - offset.get();
		if(basePosition < 0) basePosition += 1;

		float currentTime = fmod(Bot::seconds, duration.get());
		float diff = currentTime/duration.get() - basePosition;
		adjust = diff * duration.get();
	}
};

void Wave::onInterval(){
	float timeSeconds = fmod(Bot::seconds -adjust + offset.get() * duration.get(), duration.get());
	position = timeSeconds / duration.get();
	int index = position * 256.0;
	out.set(
		(float)(pgm_read_word_near(table + index)) * 0.001
	);
}

#endif
