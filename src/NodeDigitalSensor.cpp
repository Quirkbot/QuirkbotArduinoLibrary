#include "NodeDigitalSensor.h"

DigitalSensor::DigitalSensor():
HasInterval
	(this){
	registerInput(place);
	registerInput(min);
	registerInput(max);
	place = NO_LOCATION;
	min = 0;
	max = 1;
};
DigitalSensor::~DigitalSensor(){}

void DigitalSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) pinMode(place.get(), INPUT);
};

void DigitalSensor::onInterval(){
	medianFilter.push(digitalRead(place.get()));
	out.set(Bot::map(
		medianFilter.get(),
		0, 1,
		min.get(), max.get()
	));
}
