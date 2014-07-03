#ifndef Monitor_h_
#define Monitor_h_

#include "Bot.h"
#include "Node.h"
#include "HasInputCollection.h"
#include "Input.h"
#include "Streams.h"

class Monitor:
public Node,
public HasInputCollection<float>{
	public:
	
	Monitor():
	HasInputCollection<float>
		(this){
		registerInput(throttle);
		throttle = 100;

		lastPrintMillis = Bot::millis;
	};

	Input<float> throttle;


	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	float lastPrintMillis;
};

void Monitor::onInternalInputChange(BaseInput &input){

	if(&input == &throttle) return;
	if(Bot::millis - lastPrintMillis < throttle) return;

	lastPrintMillis = Bot::millis;

	for(int i = 0; i < inputCollection.size(); i++){
		Serial.print(inputCollection[i]->get(), 3);
		Serial.print("\t");
	}

	if(inputCollection.size()) Serial.print("\n");
};

#endif
