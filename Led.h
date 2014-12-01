#ifndef Led_h_
#define Led_h_

#include "CommonNodeIncludes.h"

class Led :
public Node,
public HasIn<float>{
	public:
	
	Led():
	HasIn<float>
		(this){
		registerInput(pin);
	};

	void update(){
		HasInterval::update();
	};

	Input<int> pin;	

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Led::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin) pinMode(pin.get(), OUTPUT);
	else if(&internalInput == &in) analogWrite(pin.get(), pow(in.get(), 2.5) * 255.0);
};

#endif
