#ifndef Led_h_
#define Led_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Streams.h"


class Led :
public Node,
public InputStream<float>{
	public:
	
	Led():
	InputStream<float>
		(light){
		registerInput(pin);
		registerInput(light);

		light = 0;
	};

	Input<int> pin;	
	Input<float> light;

	protected:

	void onInternalInputChange(BaseInput &input);
};
void Led::onInternalInputChange(BaseInput &input){
	if(&input == &pin) pinMode(pin.get(), OUTPUT);
	else if(&input == &light) analogWrite(pin.get(), pow(light.get(), 2.5) * 255.0);
};

#endif
