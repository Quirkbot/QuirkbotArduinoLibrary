#include "CapacitiveTouch.h"

CapacitiveTouch::CapacitiveTouch():
HasOut
	(this){
	registerInput(place);
	registerInput(min);
	registerInput(max);

	place = NO_LOCATION;
	min = 0;
	max = 1;

	filter.alpha = 0.96;
	reference.alpha = 0.98;
	reference.set(0);

	measuring = false;
}
CapacitiveTouch::~CapacitiveTouch(){}
void CapacitiveTouch::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) {
		int location = place.get();

		frontPin = Bot::locationToFrontPin(location);

		if(frontPin == NO_LOCATION) return;

		// Internal pull up
		pinMode(PULL_UP_PIN, OUTPUT);
		digitalWrite(PULL_UP_PIN, HIGH);
	}
};

void CapacitiveTouch::update(){
	if(frontPin == NO_LOCATION) return;
	if(measuring){
		if(bool(digitalRead(frontPin)) || Bot::micros > deadlineTime) {
			int reading = Bot::micros - startTime;

			// Filter the signal
			upper0.push(reading);
			upper1.push(upper0.get());
			upper2.push(upper1.get());
			upper3.push(upper2.get());

			// Apply 2 low passes and compute the differente
			filter.push(upper3.get());
			reference.push(upper3.get());

			//float diff = filter.get() - reference.get();
			//if(diff < 0) diff = -diff;

			// Map to 0 - 1
			//float value = Bot::map(diff, reference.get(), QB_CAPACITIVE_SENSOR_MAX_TIME, 0, 1);
			float value = Bot::map(filter.get(), 0, QB_CAPACITIVE_SENSOR_MAX_TIME, 0, 1);

			out.set(value);

			// Discharge pin
			pinMode(frontPin, OUTPUT);
			digitalWrite(frontPin, LOW);
			deadlineTime += QB_CAPACITIVE_SENSOR_DISCHARGE_TIME;
			measuring = false;
		}
	}

	if(Bot::micros > deadlineTime) {
		pinMode(frontPin, INPUT);
		startTime = Bot::micros;
		deadlineTime = startTime + QB_CAPACITIVE_SENSOR_MAX_TIME;
		measuring = true;
	}
}
