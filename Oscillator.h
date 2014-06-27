/*#ifndef Oscillator_h_
#define Oscillator_h_

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "ContainsOutputs.h"
#include "Streams.h"

enum OscillatorType{
	OSC_SINE = 0,
	OSC_SQUARE,
	OSC_TRIANGLE,
	OSC_PULSE,
	OSC_RAMP_UP,
	OSC_RAMP_DOWN
}


class Oscillator :
public IntervalNode,
public OutputStream<float>,
public Contains6Input<float,float,float,float,int,int>,
public Contains4Outputs<float,float,float,float>
{
	public:

	Oscillator():
	OutputStream<float>(seconds),
	Contains1Input<float>(interval),
	Contains4Outputs<float,float,float,float>(seconds,millis,micros,frames){
		interval = 1;
	};

	void onInterval();

	Input<float> type;
	Input<float> duration;
	Input<float> offset;

	Input<int> start;
	Input<int> stop;

	Output<float> value;

	private:

};

void Oscillator::onInterval(){
	seconds.set(Bot::seconds);
	millis.set(Bot::millis);
	micros.set(Bot::micros);
	frames.set(Bot::frames);
}*/

#endif
