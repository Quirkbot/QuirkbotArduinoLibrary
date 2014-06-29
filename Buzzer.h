#ifndef Buzzer_h_
#define Buzzer_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Updatable.h"
#include "Input.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Buzzer:
public Node,
public Updatable,
public InputStream<float>,
public Contains2Inputs<int, float>{
	public:
	
	Buzzer():
	InputStream<float>
		(sound),
	Contains2Inputs<int, float>
		(pin, sound){

		registerInput(pin);
		registerInput(sound);

		sound = 0;
		high = false;
	};

	void update();

	Input<int> pin;
	Input<float> sound;

	protected:

	void onInternalInputChange(BaseInput &input);

	bool high;
};
void Buzzer::onInternalInputChange(BaseInput &input){
	if(&input == &pin){
		pinMode(pin, OUTPUT);
	}
}

void Buzzer::update(){
	if(sound < 0.5) return;

	float t = fmod(Bot::millis, 4);
	if(t >= 2 && high){
		high = false;
		digitalWrite(pin, LOW);
	}
	else if(t < 2 && !high){
		high = true;
		digitalWrite(pin, HIGH);
	}
}
#endif
