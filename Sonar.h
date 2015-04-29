#ifndef Sonar_h_
#define Sonar_h_

#include "CommonNodeIncludes.h"

class Sonar :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	Sonar();

	void onInterval();

	Input<float> place;

	protected:

	MedianFilter medianFilter;
};
#endif