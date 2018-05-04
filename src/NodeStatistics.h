#ifndef NodeStatistics_h_
#define NodeStatistics_h_

#include "CommonNodeIncludes.h"

#define STAT_AVG 0
#define STAT_MIN 1
#define STAT_MAX 2
#define STAT_SUM 3

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

	void onInternalInputChange(BaseInput&);
};
#endif
