#ifndef MakeyTouch_h_
#define MakeyTouch_h_

#include "CommonNodeIncludes.h"

#define QB_MAKEY_TOUCH_MAX_TIME 10000
#define QB_MAKEY_TOUCH_DISCHARGE_TIME 1000

class MakeyTouch :
public Node,
public Updatable,
public HasOut
{
	public:

	MakeyTouch();
	~MakeyTouch();

	Input place;
	Input min;
	Input max;

	void update();

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	UpperFilter upper;
	LowPassFilter filter;

	unsigned int frontPin;
	unsigned int backPin;
	unsigned long startTime;
	unsigned long deadlineTime;
	bool measuring;
};
#endif
