#include "NodeGate.h"

Gate::Gate():
HasTrigger
	(this){
		registerInput(in);
		in = 0.0;
};
Gate::~Gate(){}

void Gate::onInternalInputChange(BaseInput &){
	if(isTriggerActive()){
		out.set(in.get());
	}
};
