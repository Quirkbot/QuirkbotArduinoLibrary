#ifndef AnalogSensor_h_
#define AnalogSensor_h_

#include "CommonNodeIncludes.h"

class AnalogSensor :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	AnalogSensor();

	void onInterval();

	InputFloat place;
	InputFloat min;
	InputFloat max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
	int pin;
};
#endif