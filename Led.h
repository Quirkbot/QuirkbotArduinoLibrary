#ifndef Led_h_
#define Led_h_

#include "CommonNodeIncludes.h"

#define QB_LED_SOFT_PWM_WIDTH 16

class Led :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	Led():
	HasIn<float>
		(this){
		registerInput(pin);
		useSoftPWM = false;
		pwmOffset = QB_LED_SOFT_PWM_WIDTH;
	};

	Input<int> pin;	

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	bool useSoftPWM;
	unsigned int pwmOffset;
	volatile uint8_t *outPort;
	uint8_t pinMask;

};
void Led::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin){
		pinMode(pin.get(), OUTPUT);
		// Activate soft pwm only for the built-in leds
		switch(pin.get()){
			case LE:
			case RE:
				useSoftPWM = true;
				outPort = portOutputRegister(digitalPinToPort(pin.get()));
				pinMask = digitalPinToBitMask(pin.get());
				break;
			case LM:
				useSoftPWM = true;
				outPort = &PORTD;
				pinMask = (1<<5);
				break;
			case RM:
				useSoftPWM = true;
				outPort = &PORTB;
				pinMask = (1<<0);
				break;
			default:
				useSoftPWM = false;
		}
	}
	else if(&internalInput == &in){
		if(useSoftPWM){
			pwmOffset = (int)((float)QB_LED_SOFT_PWM_WIDTH * pow(in.get(), 2.5));
		}
		else{
			analogWrite(pin.get(), pow(in.get(), 2.5) * 255.0);
		}

	}
};
void Led::update(){
	if(!useSoftPWM) return;

	if(Bot::frames % QB_LED_SOFT_PWM_WIDTH < pwmOffset){
		*outPort |= pinMask;
	}
	else{
		*outPort &= ~(pinMask);
	}	
};
#endif
