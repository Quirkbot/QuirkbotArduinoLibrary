#ifndef NodeAnalogSensor_h_
#define NodeAnalogSensor_h_

#include "CommonNodeIncludes.h"

class AnalogSensor :
public Node,
public HasInterval
{
	public:

	AnalogSensor();
	~AnalogSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter preMedianFilter;
	MedianFilter postMedianFilter;
	int pin;
};
#endif
