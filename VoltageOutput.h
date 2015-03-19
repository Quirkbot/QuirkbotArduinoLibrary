#ifndef VoltageOutput_h_
#define VoltageOutput_h_

#include "CommonNodeIncludes.h"

class VoltageOutput :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	VoltageOutput():
	HasIn<float>
		(this){
		registerInput(place);
		useSoftPWM = false;
		pwmWidth = 16;
		pwmOffset = pwmWidth;
		signalPin = -1;
		location = -1;
	};

	Input<float> place;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	bool useSoftPWM;
	int pwmWidth;
	unsigned int pwmOffset;
	volatile uint8_t *outPort;
	uint8_t pinMask;
	int signalPin;
	int location;

};
void VoltageOutput::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		// Disable when disconnected
		if(location != -1){
			*outPort &= ~(pinMask);
		}

		location = place.get();
		
		if(location == LM || location == RM){
			useSoftPWM = true;
			signalPin = -1;
			switch(location){
				case LM:
					outPort = &PORTD;
					pinMask = (1<<5);
					break;
				case RM:
					outPort = &PORTB;
					pinMask = (1<<0);
					break;	
			}
		}
		else{	
			signalPin = Bot::locationToFrontPin(location);
			if(signalPin == NO_LOCATION) signalPin = location;
			outPort = portOutputRegister(digitalPinToPort(signalPin));
			pinMask = digitalPinToBitMask(signalPin);
			pinMode(signalPin, OUTPUT);

			if( digitalPinToTimer(signalPin) == NOT_ON_TIMER ){
				useSoftPWM = true;				
			}
			else useSoftPWM = false;
		}
	}
	if(useSoftPWM){
		pwmOffset = (int)((float)pwmWidth * in.get());
	}
	else{
		analogWrite(signalPin, in.get() * 255.0);
	}
};
void VoltageOutput::update(){
	if(!useSoftPWM) return;

	if(Bot::frames % pwmWidth < pwmOffset){
		*outPort |= pinMask;
	}
	else{
		*outPort &= ~(pinMask);
	}	
};
#endif