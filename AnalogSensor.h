#ifndef AnalogSensor_h_
#define AnalogSensor_h_

#include "CommonNodeIncludes.h"

class AnalogSensor :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	AnalogSensor():
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

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
};

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin) pinMode(pin.get(), INPUT);
};

void AnalogSensor::onInterval(){
	preMedianFilter.push(analogRead(pin.get()));
	postMedianFilter.push(preMedianFilter.get());
	out.set(postMedianFilter.get()/1024.0);
}

#endif
