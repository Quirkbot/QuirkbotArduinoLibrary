#ifndef Time_h_
#define Time_h_

#include "CommonNodeIncludes.h"

class Time :
public Node,
public HasInterval,
public HasOut<float>
{
	public:

	Time();

	void onInterval();
};
#endif