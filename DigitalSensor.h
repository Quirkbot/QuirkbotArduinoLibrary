#ifndef DigitalSensor_h_
#define DigitalSensor_h_

#include "CommonNodeIncludes.h"

class DigitalSensor :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	DigitalSensor();

	void onInterval();

	Input<float> place;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter medianFilter;
};
#endif