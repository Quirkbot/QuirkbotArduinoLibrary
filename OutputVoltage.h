#ifndef OutputVoltage_h_
#define OutputVoltage_h_

#include "CommonNodeIncludes.h"

class OutputVoltage :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	OutputVoltage():
	HasIn<float>
		(this){
		registerInput(place);
		useSoftPWM = false;
		pwmWidth = 16;
		pwmOffset = pwmWidth;
		signalPin = -1;
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

};
void OutputVoltage::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		int location = place.get();
		
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

			pinMode(signalPin, OUTPUT);

			if( digitalPinToTimer(signalPin) == NOT_ON_TIMER ){
				useSoftPWM = true;				
				outPort = portOutputRegister(digitalPinToPort(signalPin));
				pinMask = digitalPinToBitMask(signalPin);
			}
			else useSoftPWM = false;
		}
	}
	else if(&internalInput == &in){
		if(useSoftPWM){
			pwmOffset = (int)((float)pwmWidth * in.get());
		}
		else{
			analogWrite(signalPin, in.get() * 255.0);
		}

	}
};
void OutputVoltage::update(){
	if(!useSoftPWM) return;

	if(Bot::frames % pwmWidth < pwmOffset){
		*outPort |= pinMask;
	}
	else{
		*outPort &= ~(pinMask);
	}	
};
#endif
