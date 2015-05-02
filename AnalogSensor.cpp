#include "AnalogSensor.h"

AnalogSensor::AnalogSensor():
	HasInterval
		(this),
	HasOut
		(this){
		registerInput(place);
		registerInput(min);
		registerInput(max);

		min = 0;
		max = 1;

		pin = -1;
};

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		pin = Bot::locationToBackPin(place.get());
		if(pin == NO_LOCATION){
			pin = place.get();
		}

		pinMode(pin, INPUT);
	}
};

void AnalogSensor::onInterval(){
	if(pin == -1) return;
	
	preMedianFilter.push(analogRead(pin));
	postMedianFilter.push(preMedianFilter.get());
	out.set(Bot::map(postMedianFilter.get(), 0, 1024, min.get(), max.get()));
}