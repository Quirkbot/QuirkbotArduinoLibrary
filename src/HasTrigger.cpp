#include "HasTrigger.h"

HasTrigger::HasTrigger(Node * node):
triggerNode(node){
	triggerNode->registerInput(trigger);
	
	trigger = 0;
	triggerThreshold = 0.95;
}
HasTrigger::~HasTrigger(){}
bool HasTrigger::isTriggerActive(){
	return trigger.get() > triggerThreshold;
}