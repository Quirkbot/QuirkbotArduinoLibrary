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
		nextTick = Bot::millis + (int)(interval.get()*1000);
	};

	void update(){
		if(Bot::millis >= nextTick){
			nextTick = Bot::millis + (int)(interval.get()*1000);
			onInterval();
		}
	};

	virtual void onInterval(){};

	Input<float> interval;

	private:
	int nextTick;
	Node * intervalNode;
};

#endif
