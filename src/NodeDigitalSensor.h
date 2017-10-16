#ifndef NodeDigitalSensor_h_
#define NodeDigitalSensor_h_

#include "CommonNodeIncludes.h"

class DigitalSensor :
public Node,
public HasInterval,
public HasOut
{
	public:

	DigitalSensor();
	~DigitalSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter medianFilter;
};
#endif
