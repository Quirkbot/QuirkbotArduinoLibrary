#ifndef Monitor_h_
#define Monitor_h_

#include "Bot.h"
#include "CollectionNode.h"
#include "Input.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Monitor:
public CollectionNode<float>{
	public:
	
	Monitor(){
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

	for(int i = 0; i < items.size(); i++){
		Serial.print(items[i]->get(), 3);
		Serial.print("\t");
	}

	if(items.size()) Serial.print("\n");
};

#endif
