#include "DualColorLed.h"

DualColorLed::DualColorLed(){
	registerInput(place);
	registerInput(light);
	registerInput(color);

	light = 1;
	color = 0;
	place = NO_LOCATION;

	pwmWidth = 32;
	pwmOffsetFront = pwmWidth;
	active = false;
	location = -1;
};
DualColorLed::~DualColorLed(){}

void DualColorLed::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		// Disable when disconnected
		if(location != -1){
			*outPortBack &= ~(pinMaskBack);
			*outPortFront &= ~(pinMaskFront);
		}

		location = place.get();
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
	else if(&internalInput == &light || &internalInput == &color){
		pwmOffset = (int)((float)pwmWidth * pow(light.get(), 2.5));
		pwmOffsetBack = (float)pwmOffset * color.get();
		pwmOffsetFront = pwmOffset - pwmOffsetBack;
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
