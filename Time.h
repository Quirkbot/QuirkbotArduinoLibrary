#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Time :
public IntervalNode,
public OutputStream<float>
{
	public:

	Time():
	OutputStream<float>(millis){
		interval = 1;
	};

	void onInterval();

	Output<float> seconds;
	Output<float> millis;
	Output<float> micros;
	Output<float> frames;
};

void Time::onInterval(){
	seconds.set(Bot::seconds);
	millis.set(Bot::millis);
	micros.set(Bot::micros);
	frames.set(Bot::frames);
}

#endif
