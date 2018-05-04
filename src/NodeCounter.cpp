#include "NodeCounter.h"

Counter::Counter():
HasTrigger
	(this){
};
Counter::~Counter(){
	registerInput(amount);

	amount = 1.0;

	count = 0.0;
}

void Counter::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){
		if(isTriggerActive()){
			count += amount.get();
			out.set(count);
		}
	}
};
