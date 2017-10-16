#include "NodeLightSensor.h"

LightSensor::LightSensor():
	HasInterval
		(this),
	HasOut
		(this){
		registerInput(place);
		registerInput(min);
		registerInput(max);

		place = NO_LOCATION;
		min = 0;
		max = 1;

		pin = NO_LOCATION;
};
LightSensor::~LightSensor(){}

void LightSensor::onInternalInputChange(BaseInput &internalInput){
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
};

void LightSensor::onInterval(){
	if(backPin == NO_LOCATION) return;

	filter.push(analogRead(backPin));
	// 686 as is the max value of the "black" light sensor. Discovered empirically.
	out.set(Bot::map(filter.get(), 0, 686, min.get(), max.get()));
}
