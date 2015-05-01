#ifndef Gate_h_
#define Gate_h_

#include "CommonNodeIncludes.h"

class Gate:
public Node,
public HasTrigger,
public HasIn,
public HasOut
{
	public:
	
	Gate();
	
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};
#endif