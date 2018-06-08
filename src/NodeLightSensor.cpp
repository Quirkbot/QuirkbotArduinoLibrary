#include "NodeLightSensor.h"

LightSensor::LightSensor():
	HasInterval
		(this){
		registerInput(place);
		registerInput(min);
		registerInput(max);

		place = DISCONNECTED;
		min = 0;
		max = 1;

		pin = DISCONNECTED;
};
LightSensor::~LightSensor(){}

void LightSensor::onInternalInputChange(BaseInput &internalInput){
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
};

void LightSensor::onInterval(){
	if(backPin == DISCONNECTED) return;

	filter.push(analogRead(backPin));
	// 686 as is the max value of the "black" light sensor. Discovered empirically.
	out.set(Bot::map(filter.get(), 0, 686, min.get(), max.get()));
}
