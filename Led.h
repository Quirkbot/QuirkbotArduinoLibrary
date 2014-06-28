#ifndef Led_h_
#define Led_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "ContainsInputs.h"
#include "Streams.h"


class Led :
public Node,
public InputStream<float>,
public Contains4Inputs<float, int, float, float>{
	public:
	
	Led():
	InputStream<float>
		(light),
	Contains4Inputs<float, int, float, float>
		(light,pin, on, off){
		registerInput(pin);
		registerInput(light);
		registerInput(on);
		registerInput(off);

		light = 0;
	};

	Input<int> pin;	
	Input<float> light;
	Input<float> on;
	Input<float> off;

	protected:

	void onPinChange(){
		pinMode(pin, OUTPUT);
	};
	void onBrightenessChange(){
		analogWrite(pin, pow(light, 2.5) * 255.0);
	};
	void onOn(){
		light = 1;
	};
	void onOff(){
		light = 0;
	};

	void onInternalInputChange(BaseInput &input);
};
void Led::onInternalInputChange(BaseInput &input){
	if(&input == &pin) onPinChange();
	else if(&input == &light) onBrightenessChange();
	else if(&input == &on) onOn();
	else if(&input == &off) onOff();
};

#endif
