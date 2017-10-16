#ifndef NodeLightSensor_h_
#define NodeLightSensor_h_

#include "CommonNodeIncludes.h"

class LightSensor :
public Node,
public HasInterval,
public HasOut
{
	public:

	LightSensor();
	~LightSensor();

	void onInterval();

	Input place;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	MedianFilter filter;
	int pin;
	int backPin;
	int frontPin;
};
#endif
