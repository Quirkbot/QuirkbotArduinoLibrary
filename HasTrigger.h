#ifndef HasTrigger_h_
#define HasTrigger_h_

#include "Node.h"
#include "Input.h"
#include "Output.h"
class HasTrigger{
	public:
	HasTrigger(Node * node):
	triggerNode(node){
		triggerNode->registerInput(triggerInput);
		triggerNode->registerInput(triggerThreshold);
		
		triggerInput = 0;
		triggerThreshold = 0.95;
	};

	void trigger(Output<float> &output){
		triggerInput.connect(output);
	};
	void trigger(float &value){
		triggerInput = value;
	};
	void trigger(float value){
		triggerInput = value;
	};
	void removeTrigger(){
		triggerInput.disconnect();
	};

	Input<float> triggerInput;
	Input<float> triggerThreshold;

	protected:

	bool aboveTrigger(){
		return triggerInput.get() > triggerThreshold.get();
	}

	private:

	Node * triggerNode;
};

#endif
