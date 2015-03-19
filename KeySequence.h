#ifndef KeySequence_h_
#define KeySequence_h_

#include "CommonNodeIncludes.h"

class KeySequence :
public Node,
public HasTrigger
{
	public:
	
	KeySequence():
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

void KeySequence::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){

		if(!pressed && isTriggerActive()){
			pressed = true;
			Keyboard.press(currentKey);
		}
		else if(pressed && !isTriggerActive()){
			pressed = false;
			Keyboard.release(currentKey);
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
