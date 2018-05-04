#include "NodeGate.h"

Gate::Gate():
HasTrigger
	(this){
};
Gate::~Gate(){
	registerInput(in);

	in = 0.0;
}

void Gate::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		if(isTriggerActive()){
			out.set(in.get());
		}
	}
};
