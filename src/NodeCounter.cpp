#include "NodeCounter.h"

Counter::Counter():
HasTrigger
	(this){
};
Counter::~Counter(){
	registerInput(amount);

	amount = 1.0;

	count = 0.0;
	active = false;
}

void Counter::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){
		if(!active && isTriggerActive()){
			active = true;
			count += amount.get();
			out.set(count);
		}
		else if(active && !isTriggerActive()){
			active = false;
		}
	}
};
