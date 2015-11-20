#include "Led.h"

Led::Led(){
	registerInput(light);
	registerInput(place);

	light = 1;
	place = NO_LOCATION;

	pwmCompare = Bot::INTERUPT_COUNT_OVERFLOW;
	signalPin = -1;
	location = -1;
}
Led::~Led(){}
void Led::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		// Disable when disconnected
		if(location != -1){
			*outPort &= ~(pinMask);
		}

		location = place.get();

		if(location == LM || location == RM){
			signalPin = -1;
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
		else{
			int groundPin = Bot::locationToBackPin(location);

			if(groundPin != NO_LOCATION){
				pinMode(groundPin, OUTPUT);
				digitalWrite(groundPin, LOW);
			}

			signalPin = Bot::locationToFrontPin(location);
			if(signalPin == NO_LOCATION) signalPin = location;
			uint8_t SaveSREG = SREG;   // save interrupt flag
			cli();   // disable interrupts
			outPort = portOutputRegister(digitalPinToPort(signalPin));
			pinMask = digitalPinToBitMask(signalPin);
			SREG = SaveSREG;   // restore the interrupt flag
			pinMode(signalPin, OUTPUT);
		}
		isOn = false;
	}

	pwmCompare = (int)((float)Bot::INTERUPT_COUNT_OVERFLOW * pow(light.get(), 1.5));
}
volatile void Led::interruptUpdate(){
	if(Bot::interruptCount < pwmCompare && !isOn){
		*outPort |= pinMask;
		isOn = true;
	}
	else if(Bot::interruptCount >= pwmCompare && isOn){
		*outPort &= ~(pinMask);
		isOn = false;
	}
}
void Led::serialReport(){
	byte b = (byte)Bot::map(light.get(), 0, 1.0, 0, 249);
	Serial.write(b);
}
