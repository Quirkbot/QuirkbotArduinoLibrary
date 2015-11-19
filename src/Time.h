#ifndef Time_h_
#define Time_h_

#include "CommonNodeIncludes.h"

class Time :
public Node,
public HasInterval,
public HasOut
{
	public:

	Time();
	~Time();

	void onInterval();
};
#endif