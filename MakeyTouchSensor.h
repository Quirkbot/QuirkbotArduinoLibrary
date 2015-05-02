#ifndef MakeyTouchSensor_h_
#define MakeyTouchSensor_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_MAKEY_SENSORS 5

class MakeyTouchSensor :
public Node,
public Updatable,
public HasOut
{
	public:
	
	MakeyTouchSensor();

	Input place;

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