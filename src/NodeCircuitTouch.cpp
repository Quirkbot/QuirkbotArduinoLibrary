#include "NodeCircuitTouch.h"

CircuitTouch::CircuitTouch():
HasOut
	(this){
	registerInput(place);
	registerInput(min);
	registerInput(max);
	registerInput(sensitivity);

	place = NO_LOCATION;
	min = 0;
	max = 1;
	sensitivity = 0;

	filter.alpha = 0.7;

	measuring = false;
}
CircuitTouch::~CircuitTouch(){}
void CircuitTouch::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) {
		int location = place.get();

		frontPin = Bot::locationToFrontPin(location);
		if(frontPin == NO_LOCATION) return;

		backPin = Bot::locationToBackPin(location);
		if(backPin == NO_LOCATION) return;

		// Internal pull up
		pinMode(PULL_UP_PIN, OUTPUT);
		digitalWrite(PULL_UP_PIN, HIGH);

		// Set back pin as ground
		pinMode(backPin, OUTPUT);
		digitalWrite(backPin, LOW);
	}
};

void CircuitTouch::update(){
	if(frontPin == NO_LOCATION) return;
	if(measuring){
		if(bool(digitalRead(frontPin)) || ::micros() > deadlineTime) {
			int reading = ::micros() - startTime;

			// Filter the signal
			upper.push(reading);
			filter.push(upper.get());

			// Activate if over threshold
			float threshold = QB_CIRCUIT_TOUCH_MAX_TIME * (1 - Bot::map(sensitivity.get(),0,1,0,0.95));
			float value = (filter.get() >= threshold) ? 1.0: 0;
			value = Bot::map(value, 0, 1, min.get(), max.get());
			out.set(value);

			// Discharge pin
			pinMode(frontPin, OUTPUT);
			digitalWrite(frontPin, LOW);
			deadlineTime =  deadlineTime + QB_CIRCUIT_TOUCH_DISCHARGE_TIME;
			measuring = false;
		}
	}

	if(::micros() > deadlineTime) {
		// Charge pin
		pinMode(frontPin, INPUT);
		startTime = ::micros();
		deadlineTime = startTime + QB_CIRCUIT_TOUCH_MAX_TIME;
		measuring = true;
	}
}
