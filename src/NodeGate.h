#ifndef NodeGate_h_
#define NodeGate_h_

#include "CommonNodeIncludes.h"

class Gate:
public Node,
public HasTrigger
{
	public:

	Gate();
	~Gate();

	Input in;

	Output out;

	protected:
	void onInternalInputChange(BaseInput &);
};
#endif
