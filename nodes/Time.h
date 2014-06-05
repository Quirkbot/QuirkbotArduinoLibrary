#ifndef Time_h_
#define Time_h_

#include "Bot.h"
#include "Node.h"
#include "Updatable.h"
#include "Output.h"

class Time : public Node, public Updatable{
	public:
	
	void update();

	Output frames;
	Output micros;
	Output millis;
	Output seconds;
};

#endif
