#ifndef AnalogSensor_h_
#define AnalogSensor_h_

#include "CommonNodeIncludes.h"

class AnalogSensor :
public Node,
public HasInterval,
public HasOut
{
	public:
	
	AnalogSensor();
	~AnalogSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
	int pin;
};
#endif