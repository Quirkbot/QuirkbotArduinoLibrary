#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"

class Node;
class Updatable;

class Time : public IntervalNode{
	public:

	void onInterval();

	Output<int> frames;
	Output<float> micros;
	Output<float> millis;
	Output<float> seconds;
};

#endif
