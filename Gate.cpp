#include "Gate.h"

Gate::Gate():
HasTrigger
	(this),
HasIn<float>
	(this),
HasOut<float>
	(this){
};

void Gate::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		if(isTriggerActive()){
			out.set(in.get());
		}
	}
};