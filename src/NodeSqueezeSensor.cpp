#include "NodeSqueezeSensor.h"

SqueezeSensor::SqueezeSensor():
HasInterval
	(this){
	registerInput(place);
	registerInput(min);
	registerInput(max);

	place = DISCONNECTED;
	min = 0;
	max = 1;

	reference.factor = 0.7;
	refMin = 1024;
	refMax = 0;
}
SqueezeSensor::~SqueezeSensor(){}
void SqueezeSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		backPin = Bot::locationToBackPin(place.get());
		frontPin = Bot::locationToFrontPin(place.get());

		if(backPin != DISCONNECTED &&  frontPin != DISCONNECTED){
			pinMode(backPin, INPUT);
			digitalWrite(backPin, LOW);
			pinMode(frontPin, OUTPUT);
			digitalWrite(frontPin, HIGH);
		}
	}
}
void SqueezeSensor::onInterval(){
	if(backPin == DISCONNECTED ||  frontPin == DISCONNECTED) return;

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
