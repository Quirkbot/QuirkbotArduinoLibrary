#include "SqueezeSensor.h"

SqueezeSensor::SqueezeSensor():
HasInterval
	(this),
HasOut
	(this){
	registerInput(place);

	place = NO_LOCATION;

	min = 0;
	max = 1;

	reference.alpha = 0.7;
	refMin = 1024;
	refMax = 0;
}
SqueezeSensor::~SqueezeSensor(){}
void SqueezeSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		backPin = Bot::locationToBackPin(place.get());
		frontPin = Bot::locationToFrontPin(place.get());

		if(backPin != NO_LOCATION &&  frontPin != NO_LOCATION){
			pinMode(backPin, INPUT);
			digitalWrite(backPin, LOW);
			pinMode(frontPin, OUTPUT);
			digitalWrite(frontPin, HIGH);
		}
	}
}
void SqueezeSensor::onInterval(){
	if(backPin == NO_LOCATION ||  frontPin == NO_LOCATION) return;

	float reading = analogRead(backPin);

	// Calculate the minimum and maximum reference values
	reference.push(reading);

	// Initial delay for low pass to stabilize from 0
	if(::millis() < 2500) return;

	refMin = Bot::minimum(refMin, reference.get());
	refMax = Bot::maximum(refMax, reference.get());

	filter.push(reading);
	float value = Bot::map(filter.get(), refMin, refMax, 0, 1);
	value = pow(value, 0.5);
	value = Bot::map(value, 0, 1, min.get(), max.get());
	out.set(value);
}
