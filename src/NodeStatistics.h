#ifndef NodeStatistics_h_
#define NodeStatistics_h_

#include "CommonNodeIncludes.h"

#define STATISTICS_AVERAGE 0
#define STATISTICS_MIN 1
#define STATISTICS_MAX 2
#define STATISTICS_SUM 3

class Statistics :
public Node
{
	public:

	Statistics();
	~Statistics();

	Input operation;
	InputCollection items;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
