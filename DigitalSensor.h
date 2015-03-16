#ifndef DigitalSensor_h_
#define DigitalSensor_h_

#include "CommonNodeIncludes.h"

class DigitalSensor :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	DigitalSensor():
	HasInterval
		(this),
	HasOut<float>
		(this){
		registerInput(place);
	};

	void onInterval();

	Input<int> place;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter medianFilter;
};

void DigitalSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) pinMode(place.get(), INPUT);
};

void DigitalSensor::onInterval(){
	medianFilter.push(digitalRead(place.get()));
	out.set(medianFilter.get());
}

#endif
