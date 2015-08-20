#include "DigitalSensor.h"

DigitalSensor::DigitalSensor():
HasInterval
	(this),
HasOut
	(this){
	registerInput(place);
	place = NO_LOCATION;
};
DigitalSensor::~DigitalSensor(){}

void DigitalSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) pinMode(place.get(), INPUT);
};

void DigitalSensor::onInterval(){
	medianFilter.push(digitalRead(place.get()));
	out.set(medianFilter.get());
}
