#include "NodeKeyPress.h"

KeyPress::KeyPress():
HasTrigger
	(this){
	registerInput(key);

	key = NO_KEY;
	currentKey = 0;
	pressed = false;
};
KeyPress::~KeyPress(){}

void KeyPress::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){

		if(!pressed && isTriggerActive()){
			pressed = true;
			if(currentKey != NO_KEY) Bot::pressKey(currentKey);
		}
		else if(pressed && !isTriggerActive()){
			pressed = false;
			if(currentKey != NO_KEY) Bot::releaseKey(currentKey);
			currentKey = key.get();
		}

	}
	else if(&internalInput == &key){

		if(!isTriggerActive()){
			currentKey = key.get();
		}
	}
};
