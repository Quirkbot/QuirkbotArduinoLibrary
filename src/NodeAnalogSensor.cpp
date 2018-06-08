#include "NodeAnalogSensor.h"

AnalogSensor::AnalogSensor():
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
AnalogSensor::~AnalogSensor(){}

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		pin = Bot::locationToAnalogPin(place.get());

		if(pin == DISCONNECTED){
			pin = place.get();
		}

		pinMode(pin, INPUT);
	}
};

void AnalogSensor::onInterval(){
	if(pin == DISCONNECTED) return;

	preFilterMedian.push(analogRead(pin));
	postFilterMedian.push(preFilterMedian.get());
	out.set(Bot::map(
		postFilterMedian.get(),
		0, 1024,
		min.get(), max.get()
	));
}
