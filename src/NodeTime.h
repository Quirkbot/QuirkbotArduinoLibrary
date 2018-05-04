#ifndef NodeTime_h_
#define NodeTime_h_

#include "CommonNodeIncludes.h"

class Time :
public Node,
public HasInterval
{
	public:

	Time();
	~Time();

	Output out;

	void onInterval();
};
#endif
