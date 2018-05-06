#ifndef NodeDigitalSensor_h_
#define NodeDigitalSensor_h_

#include "CommonNodeIncludes.h"

class DigitalSensor :
public Node,
public HasInterval
{
	public:

	DigitalSensor();
	~DigitalSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	FilterMedian medianFilter;
};
#endif
