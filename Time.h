#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "Node.h"
//#include "Updatable.h"
#include "Input.h"
#include "Output.h"

class Node;
class Updatable;

class Time : public Node, public Updatable{
	public:
	Time();

	void update();

	Input<float> interval;

	Output<int> frames;
	Output<float> micros;
	Output<float> millis;
	Output<float> seconds;

	protected:
	void onInternalInputChange(BaseInput &input);
	void onIntervalChange();
	
};

#endif
