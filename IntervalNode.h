#ifndef IntervalNode_h_
#define IntervalNode_h_

#include "Bot.h"
#include "Node.h"
#include "Updatable.h"
#include "Input.h"
#include "Output.h"

class Node;
class Updatable;

class IntervalNode : public Node, public Updatable{
	public:
	IntervalNode();

	void update();

	virtual void onInterval(){};

	Input<float> interval;

	protected:
	void onInternalInputChange(BaseInput &input);
	void onIntervalChange();	
};

#endif
