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
	HasInterval(Node * node);

	void update();

	virtual void onInterval(){};

	Input interval;

	private:
	unsigned long nextTick;
	Node * intervalNode;
};

#endif
