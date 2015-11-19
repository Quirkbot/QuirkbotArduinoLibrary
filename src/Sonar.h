#ifndef Sonar_h_
#define Sonar_h_

#include "CommonNodeIncludes.h"

class Sonar :
public Node,
public HasInterval,
public HasOut
{
	public:

	Sonar();
	~Sonar();

	void onInterval();

	Input meters;
	Input place;
	Input min;
	Input max;

	protected:

	MedianFilter medianFilter;
};
#endif
