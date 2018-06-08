#include "NodeLed.h"

Led::Led(){
	registerInput(light);
	registerInput(place);

	light = 1;
	place = DISCONNECTED;

	pwmCompare = Bot::INTERUPT_COUNT_OVERFLOW;
	signalPin = DISCONNECTED;
	location = DISCONNECTED;
}
Led::~Led(){}
void Led::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		// Disable when disconnected
		if(location != DISCONNECTED){
			*outPort &= ~(pinMask);
		}

		location = place.get();

		if(location == LM || location == RM){
			signalPin = DISCONNECTED;
			switch(location){
				case LM:
					outPort = &PORTD;
					pinMask = (1<<5);
					DDRD |= (1<<5); // pinMode OUTPUT
					break;
				case RM:
					outPort = &PORTB;
					pinMask = (1<<0);
					DDRB |= (1<<0); // pinMode OUTPUT
					break;
			}
		}
		else if(location != DISCONNECTED){
			int groundPin = Bot::locationToBackPin(location);

			if(groundPin != DISCONNECTED){
				pinMode(groundPin, OUTPUT);
				digitalWrite(groundPin, LOW);
			}

			signalPin = Bot::locationToFrontPin(location);
			if(signalPin == DISCONNECTED) signalPin = location;
			uint8_t SaveSREG = SREG;   // save interrupt flag
			cli();   // disable interrupts
			outPort = portOutputRegister(digitalPinToPort(signalPin));
			pinMask = digitalPinToBitMask(signalPin);
			SREG = SaveSREG;   // restore the interrupt flag
			pinMode(signalPin, OUTPUT);
		}
		else{
			signalPin = DISCONNECTED;
		}
		isOn = false;
	}
	else if(&internalInput == &light){
		pwmCompare = (int)((float)Bot::INTERUPT_COUNT_OVERFLOW * pow(light.get(), 1.5));
	}
}
void Led::interruptUpdate(){
	if(location != DISCONNECTED){
		if(Bot::interruptCount < pwmCompare && !isOn){
			*outPort |= pinMask;
			isOn = true;
		}
		else if(!pwmCompare || (Bot::interruptCount >= pwmCompare && isOn)){
			*outPort &= ~(pinMask);
			isOn = false;
		}
	}

}
