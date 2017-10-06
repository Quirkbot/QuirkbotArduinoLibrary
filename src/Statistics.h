#ifndef Statistics_h_
#define Statistics_h_

#include "CommonNodeIncludes.h"

#define STATISICS_AVERAGE 0
#define STATISICS_MIN 1
#define STATISICS_MAX 2
#define STATISICS_SUM 3

class Statistics :
public Node,
public HasOut
{
	public:

	Statistics();
	~Statistics();

	Input operation;
	InputCollection items;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
