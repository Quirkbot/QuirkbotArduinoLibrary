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
		registerInput(min);
		registerInput(max);

		min = 0;
		max = 1;

		pin = -1;
	};

	void onInterval();

	Input<float> place;
	Input<float> min;
	Input<float> max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
	int pin;
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

#endif
