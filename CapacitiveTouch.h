#ifndef CapacitiveTouch_h_
#define CapacitiveTouch_h_

#include "CommonNodeIncludes.h"

#define QB_CAPACITIVE_SENSOR_MAX_TIME 1500
#define QB_CAPACITIVE_SENSOR_DISCHARGE_TIME 1000

class CapacitiveTouch :
public Node,
public Updatable,
public HasOut
{
	public:

	CapacitiveTouch();
	~CapacitiveTouch();

	Input place;
	Input min;
	Input max;

	void update();

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	LowPassFilter filter;

	UpperFilter upper0;
	UpperFilter upper1;
	UpperFilter upper2;
	UpperFilter upper3;

	LowPassFilter reference;
	unsigned int frontPin;
	unsigned long startTime;
	unsigned long deadlineTime;
	bool measuring;
};
#endif
