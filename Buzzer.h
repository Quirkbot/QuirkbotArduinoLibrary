#ifndef Buzzer_h_
#define Buzzer_h_

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
	InputStream<float>,
		(frequency),
	Contains3Inputs<int, float, float, float>
		(pin, frequency, play, stop){

		registerInput(pin);
		registerInput(frequency);
		registerInput(play);
		registerInput(stop);

		frequency = 440;
		stop();
	};

	Input<int> pin;

	Input<float> frequency;
	
	Input<float> play;
	Input<float> stop;

	protected:

	void onInternalInputChange(BaseInput &input);
};
Buzzer::onInternalInputChange(BaseInput &input){
	if(&input == &play){
		tone(pin, frequency);
	}
	if(&input == &stop){
		noTone(pin);
	}

}
#endif
