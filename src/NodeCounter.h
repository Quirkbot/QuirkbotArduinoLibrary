#ifndef NodeCounter_h_
#define NodeCounter_h_

#include "CommonNodeIncludes.h"

class Counter:
public Node,
public HasTrigger
{
	public:

	Counter();
	~Counter();

	Input amount;

	Output out;

	protected:
	void onInternalInputChange(BaseInput &internalInput);

	float count;
	bool active;
};
#endif
