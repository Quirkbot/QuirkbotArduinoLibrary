#ifndef SqueezeSensor_h_
#define SqueezeSensor_h_

#include "CommonNodeIncludes.h"

class SqueezeSensor :
public Node,
public HasInterval,
public HasOut
{
	public:

	SqueezeSensor();
	~SqueezeSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	LowPassFilter reference;
	float refMin;
	float refMax;
	int backPin;
	int frontPin;
	MedianFilter filter;
};
#endif