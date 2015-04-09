#ifndef KeyPress_h_
#define KeyPress_h_

#include "CommonNodeIncludes.h"

class KeyPress :
public Node,
public HasTrigger
{
	public:
	
	KeyPress():
	HasTrigger
		(this){
		registerInput(key);

		currentKey = 0;
		pressed = 5;
	};

	Input<float> key;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	int currentKey;
	bool pressed;
};

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


#endif
