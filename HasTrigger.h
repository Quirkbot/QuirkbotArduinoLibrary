#ifndef HasTrigger_h_
#define HasTrigger_h_

#include "Node.h"
#include "Input.h"
class HasTrigger{
	public:
	HasTrigger(Node * node):
	triggerNode(node){
		triggerNode->registerInput(trigger);
		triggerNode->registerInput(triggerThreshold);
		
		trigger = 0;
		triggerThreshold = 0.95;
	};

	Input<float> trigger;
	Input<float> triggerThreshold;

	protected:

	bool aboveTrigger(){
		return trigger > triggerThreshold;
	}

	private:

	Node * triggerNode;
};

#endif
