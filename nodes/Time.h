#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "Node.h"
#include "Updatable.h"
#include "Output.h"

class Time : public Node, public Updatable{
	public:
	
	void update();

	//Input<float> interval;
	//Event<float> tick;

	Output<int> frames;
	Output<float> micros;
	Output<float> millis;
	Output<float> seconds;

	
};

#endif
