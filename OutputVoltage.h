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
		registerInput(where);
		useSoftPWM = false;
		pwmWidth = 16;
		pwmOffset = pwmWidth;
		singnalPin = -1;
	};

	Input<float> where;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	bool useSoftPWM;
	int pwmWidth;
	unsigned int pwmOffset;
	volatile uint8_t *outPort;
	uint8_t pinMask;
	int singnalPin;

};
void OutputVoltage::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &where){
		int location = where.get();
		
		if(location == LM || location == RM){
			useSoftPWM = true;
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
			singnalPin = Bot::locationToFrontPin(location);
			if(singnalPin == NO_LOCATION) singnalPin = location;

			if( digitalPinToTimer(singnalPin) == NOT_ON_TIMER ){
				useSoftPWM = true;				
				outPort = portOutputRegister(digitalPinToPort(singnalPin));
				pinMask = digitalPinToBitMask(singnalPin);
			}
			else useSoftPWM = false;
		}
	}
	else if(&internalInput == &in){
		if(useSoftPWM){
			pwmOffset = (int)((float)pwmWidth * in.get());
		}
		else{
			analogWrite(singnalPin, in.get() * 255.0);
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
