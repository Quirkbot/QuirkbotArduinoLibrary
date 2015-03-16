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
		registerInput(place);
	};

	void onInterval();

	Input<float> place;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
};

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) pinMode(place.get(), INPUT);
};

void AnalogSensor::onInterval(){
	preMedianFilter.push(analogRead(place.get()));
	postMedianFilter.push(preMedianFilter.get());
	out.set(postMedianFilter.get()/1024.0);
}

#endif
