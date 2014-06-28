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
public Contains4Inputs<int, float, float, float>{
	public:
	
	Buzzer():
	InputStream<float>
		(volume),
	Contains4Inputs<int, float, float, float>
		(pin, volume, play, stop){

		registerInput(pin);
		registerInput(volume);
		registerInput(play);
		registerInput(stop);

		volume = 0.5;
		stop();
	};

	Input<int> pin;

	Input<float> volume;
	
	Input<float> play;
	Input<float> stop;

	protected:

	void onInternalInputChange(BaseInput &input);

	bool playing;
};
void Buzzer::onInternalInputChange(BaseInput &input){
	if(&input == &pin){
		pinMode(pin, OUTPUT);
	}
	if(&input == &play){
		playing = true;
		analogWrite(pin, volume * 255);
	}
	if(&input == &stop){
		playing = false;
		digitalWrite(pin, LOW);
	}
	if(&input == &volume){
		if(playing){
			analogWrite(pin, volume * 255);
		}
		else {
			digitalWrite(pin, LOW);
		}
	}
}
#endif
