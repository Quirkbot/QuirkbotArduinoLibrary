#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "HasOut.h"

class Time :
public Node,
public HasInterval,
public HasOut<float>
{
	public:

	Time():
	HasInterval
		(this),
	HasOut<float>
		(this){
		interval = 0.001;
	};

	void onInterval();
};

void Time::onInterval(){
	out.set(Bot::seconds);
}

#endif
