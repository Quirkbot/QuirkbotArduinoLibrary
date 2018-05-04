#include "NodeAnalogSensor.h"

AnalogSensor::AnalogSensor():
	HasInterval
		(this){
		registerInput(place);
		registerInput(min);
		registerInput(max);

		place = NO_LOCATION;
		min = 0;
		max = 1;

		pin = NO_LOCATION;
};
AnalogSensor::~AnalogSensor(){}

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		pin = Bot::locationToAnalogPin(place.get());

		if(pin == NO_LOCATION){
			pin = place.get();
		}

		pinMode(pin, INPUT);
	}
};

void AnalogSensor::onInterval(){
	if(pin == NO_LOCATION) return;

	preMedianFilter.push(analogRead(pin));
	postMedianFilter.push(preMedianFilter.get());
	out.set(Bot::map(
		postMedianFilter.get(),
		0, 1024,
		min.get(), max.get()
	));
}
