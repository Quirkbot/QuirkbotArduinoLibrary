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
		registerInput(pin);
	};

	void onInterval();

	Input<int> pin;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter medianFilter;
};

void DigitalSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin) pinMode(pin.get(), INPUT);
};

void DigitalSensor::onInterval(){
	medianFilter.push(digitalRead(pin.get()));
	out.set(medianFilter.get());
}

#endif
