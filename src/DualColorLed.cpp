#include "DualColorLed.h"

DualColorLed::DualColorLed(){
	registerInput(place);
	registerInput(light);
	registerInput(color);

	isOnFront = true;
	isOnBack = true;
	pwmStartBack = 0;
	pwmEndBack = 0;
	pwmStartFront = 0;
	pwmEndFront = 0;
	active = false;
	location = NO_LOCATION;

	light = 1;
	color = 0;
	place = NO_LOCATION;
};
DualColorLed::~DualColorLed(){}

void DualColorLed::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		// Disable when disconnected
		if(location != NO_LOCATION){
			*outPortBack &= ~(pinMaskBack);
			*outPortFront &= ~(pinMaskFront);
		}

		location = place.get();
		backPin = Bot::locationToBackPin(location);
		frontPin = Bot::locationToFrontPin(location);

		if(backPin == NO_LOCATION || frontPin == NO_LOCATION){
			active = false;
			*outPortBack &= ~(pinMaskBack);
			*outPortFront &= ~(pinMaskFront);
			return;
		}
		active = true;

		uint8_t SaveSREG = SREG;   // save interrupt flag
		cli();   // disable interrupts

		outPortBack = portOutputRegister(digitalPinToPort(backPin));
		pinMaskBack = digitalPinToBitMask(backPin);

		outPortFront = portOutputRegister(digitalPinToPort(frontPin));
		pinMaskFront = digitalPinToBitMask(frontPin);

		isOnFront = true;
		isOnBack = true;

		SREG = SaveSREG;   // restore the interrupt flag

		pinMode(backPin, OUTPUT);
		pinMode(frontPin, OUTPUT);

	}
	else if(&internalInput == &light || &internalInput == &color){
		uint8_t pwmSize = (int)((float)(Bot::INTERUPT_COUNT_OVERFLOW-1)  * pow(light.get(), 1.5));

		pwmStartBack = 0;
		pwmEndBack = (float)(pwmSize ) * color.get();

		pwmStartFront = pwmEndBack;
		pwmEndFront = pwmStartFront + (pwmSize - pwmStartFront);

	}
};
volatile void DualColorLed::interruptUpdate(){
	if(!active) return;

	if(Bot::interruptCount >= pwmStartBack && Bot::interruptCount < pwmEndBack && !isOnBack){
		*outPortBack |= pinMaskBack;
		isOnBack = true;
	}
	else if(Bot::interruptCount >= pwmEndBack && isOnBack){
		*outPortBack &= ~(pinMaskBack);
		isOnBack = false;
	}

	if(Bot::interruptCount >= pwmStartFront && Bot::interruptCount < pwmEndFront && !isOnFront){
		*outPortFront |= pinMaskFront;
		isOnFront = true;
	}
	else if((Bot::interruptCount < pwmStartFront || Bot::interruptCount >= pwmEndFront) && isOnFront){
		*outPortFront &= ~(pinMaskFront);
		isOnFront = false;
	}
};
