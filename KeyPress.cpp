#include "KeyPress.h"

KeyPress::KeyPress():
HasTrigger
	(this){
	registerInput(key);

	key = KEY_SPACE;
	currentKey = 0;
	pressed = 5;
};
KeyPress::~KeyPress(){}

void KeyPress::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){

		if(!pressed && isTriggerActive()){
			pressed = true;
			Bot::pressKey(currentKey);
		}
		else if(pressed && !isTriggerActive()){
			pressed = false;
			Bot::releaseKey(currentKey);
			currentKey = key.get();
		}

	}
	else if(&internalInput == &key){

		if(!isTriggerActive()){
			currentKey = key.get();
		}
	}
};
