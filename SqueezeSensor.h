#ifndef SqueezeSensor_h_
#define SqueezeSensor_h_

#include "CommonNodeIncludes.h"

class SqueezeSensor :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	SqueezeSensor():
	HasInterval
		(this),
	HasOut<float>
		(this){
		registerInput(place);

		place = 0;

		min = 0;
		max = 1;

		reference.alpha = 0.9;
		refMin = 1024;
		refMax = 0;
	};

	void onInterval();

	Input<float> place;
	Input<float> min;
	Input<float> max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	LowPassFilter reference;
	float refMin;
	float refMax;
	int backPin;
	int frontPin;
	MedianFilter filter;
};

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
};

void SqueezeSensor::onInterval(){
	if(backPin == NO_LOCATION ||  frontPin == NO_LOCATION) return;

	float reading = analogRead(backPin);

	// Calculate the minimum and maximum reference values
	reference.push(reading);

	// Initial delay for low pass to stabilize from 0
	if(Bot::seconds < 2.5) return;

	refMin = Bot::minimum(refMin, reference.get());
	refMax = Bot::maximum(refMax, reference.get());

	filter.push(reading);
	float value = Bot::map(filter.get(), refMin, refMax, min.get(), max.get());
	out.set(value);
}

#endif
