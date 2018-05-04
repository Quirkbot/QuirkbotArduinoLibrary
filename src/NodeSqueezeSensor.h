#ifndef NodeSqueezeSensor_h_
#define NodeSqueezeSensor_h_

#include "CommonNodeIncludes.h"

class SqueezeSensor :
public Node,
public HasInterval
{
	public:

	SqueezeSensor();
	~SqueezeSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	Output out;

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
