#ifndef DualColorLed_h_
#define DualColorLed_h_

#include "CommonNodeIncludes.h"

class DualColorLed :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	DualColorLed():
	HasIn<float>
		(this){
		registerInput(place);
		registerInput(color);

		in = 0;
		color = 0;

		pwmWidth = 32;		
		pwmOffsetFront = pwmWidth;
		active = false;
	};

	Input<float> place;
	Input<float> color;
	

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	int pwmWidth;
	
	unsigned int pwmOffset;
	unsigned int pwmOffsetFront;
	unsigned int pwmOffsetBack;
	
	int frontPin;
	volatile uint8_t *outPortFront;
	uint8_t pinMaskFront;

	int backPin;
	volatile uint8_t *outPortBack;
	uint8_t pinMaskBack;

	bool active;

};
void DualColorLed::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		int location = place.get();
		backPin = Bot::locationToBackPin(location);
		frontPin = Bot::locationToFrontPin(location);

		if(backPin == NO_LOCATION || frontPin == NO_LOCATION){
			active = false;
			return;
		}
		active = true;

		outPortBack = portOutputRegister(digitalPinToPort(backPin));
		pinMaskBack = digitalPinToBitMask(backPin);

		outPortFront = portOutputRegister(digitalPinToPort(frontPin));
		pinMaskFront = digitalPinToBitMask(frontPin);
		
		pinMode(backPin, OUTPUT);		
		pinMode(frontPin, OUTPUT);

	}
	else if(&internalInput == &in || &internalInput == &color){
		pwmOffset = (int)((float)pwmWidth * pow(in.get(), 2.5));
		pwmOffsetFront = (float)pwmOffset * color.get();
		pwmOffsetBack = pwmOffset - pwmOffsetFront;
	}
};
void DualColorLed::update(){
	if(!active) return;

	int index = Bot::frames % pwmWidth;

	if(index == 0){
		digitalWrite(backPin, LOW);
	}
	else if(index == pwmOffsetFront){
		digitalWrite(frontPin, LOW);
	}

	if(index < pwmOffsetFront){
		*outPortFront |= pinMaskFront;
	}
	else if(index < pwmOffsetBack){
		*outPortBack |= pinMaskBack;
	}
	else{
		*outPortFront &= ~(pinMaskFront);
		*outPortBack &= ~(pinMaskBack);
	}	
};
#endif
