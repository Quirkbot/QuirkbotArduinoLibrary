#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"
#include "ContainsOutputs.h"
#include "Streams.h"

class Node;
class Updatable;

class Time :
public IntervalNode,
public OutputStream<float>,
public Contains4Outputs<float,float,float,float>
{
	public:

	Time():
	OutputStream<float>(seconds),
	Contains4Outputs<float,float,float,float>(seconds,millis,micros,frames){

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
