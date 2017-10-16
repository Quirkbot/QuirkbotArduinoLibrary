#ifndef NodeTime_h_
#define NodeTime_h_

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
