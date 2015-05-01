#ifndef HasTrigger_h_
#define HasTrigger_h_

#include "Node.h"
#include "InputFloat.h"
#include "OutputFloat.h"
class HasTrigger{
	public:
	HasTrigger(Node * node);

	InputFloat trigger;
	float triggerThreshold;

	protected:

	bool isTriggerActive();

	private:

	Node * triggerNode;
};
#endif