#ifndef NodeSonar_h_
#define NodeSonar_h_

#include "CommonNodeIncludes.h"

class Sonar :
public Node,
public HasInterval
{
	public:

	Sonar();
	~Sonar();

	void onInterval();

	Input meters;
	Input place;
	Input min;
	Input max;

	Output out;

	protected:

	MedianFilter medianFilter;
};
#endif
