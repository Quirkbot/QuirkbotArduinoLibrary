#ifndef HasInterval_h_
#define HasInterval_h_

#include "Bot.h"
#include "Updatable.h"
#include "Input.h"
#include "Output.h"

class Node;
class Updatable;

class HasInterval:
public Updatable{
	public:
	HasInterval(Node * node):
	intervalNode(node){
		intervalNode->registerInput(interval);
		interval = 0.1;
	};

	void update(){

		int millis = (int)(Bot::seconds*1000);
		if(millis % (int)(interval.get()*1000) == 0
			&& lastMillis != millis){
			
			lastMillis = Bot::millis;
			onInterval();
		}
	};

	virtual void onInterval(){};

	Input<float> interval;

	private:
	int lastMillis;
	Node * intervalNode;
};

#endif
