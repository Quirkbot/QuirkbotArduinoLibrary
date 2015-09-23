#ifndef MakeyTouch_h_
#define MakeyTouch_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_MAKEY_SENSORS 5

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
	void serialReport();

	LowPassFilter filter;
	MedianFilter median;

	unsigned int frontPin;
	unsigned int backPin;
	unsigned int tickA;
	unsigned int tickB;


};
#endif
