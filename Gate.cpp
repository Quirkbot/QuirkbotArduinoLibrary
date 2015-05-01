#include "Gate.h"

Gate::Gate():
HasTrigger
	(this),
HasIn
	(this),
HasOut
	(this){
};

void Gate::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		if(isTriggerActive()){
			out.set(in.get());
		}
	}
};