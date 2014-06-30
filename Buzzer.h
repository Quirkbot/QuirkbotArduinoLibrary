#ifndef Buzzer_h_
#define Buzzer_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Buzzer:
public Node,
public InputStream<float>,
public Contains3Inputs<int, float, float>{
	public:
	
	Buzzer():
	InputStream<float>
		(tone),
	Contains3Inputs<int, float, float>
		(pin, tone, sound){

		registerInput(pin);
		registerInput(tone);
		registerInput(sound);

		sound = 1;

		lastSound = -1;
		lastTone = 0;
		maxFrequency = 3000.0;

		tone = 440 / maxFrequency;
	};

	void process();

	Input<int> pin;
	Input<float> tone;
	Input<float> sound;

	float maxFrequency;

	protected:

	void onInternalInputChange(BaseInput &input);

	float lastSound;
	float lastTone;
};
void Buzzer::onInternalInputChange(BaseInput &input){
	if(&input == &pin){
		pinMode(pin, OUTPUT);
		process();
	}
	else if(&input == &sound || &input == &tone){
		process();
	}
}
void Buzzer::process(){
	if(lastTone == tone && lastSound == sound) return;
	if(sound >= 0.5 && tone > 0) {
		::tone(4, (tone * tone) * maxFrequency);
	}
	else{
		noTone(pin);
	}
}

#endif
