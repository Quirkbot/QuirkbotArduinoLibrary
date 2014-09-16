#ifndef HasTrigger_h_
#define HasTrigger_h_

#include "Node.h"
#include "Input.h"
#include "Output.h"
class HasTrigger{
	public:
	HasTrigger(Node * node):
	triggerNode(node){
		triggerNode->registerInput(trigger);
		
		trigger = 0;
		triggerThreshold = 0.95;
	};

	Input<float> trigger;
	float triggerThreshold;

	protected:

	bool isTriggerActive(){
		return trigger.get() > triggerThreshold;
	}

	private:

	Node * triggerNode;
};

#endif
