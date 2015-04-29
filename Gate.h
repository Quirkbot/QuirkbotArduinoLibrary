#ifndef Gate_h_
#define Gate_h_

#include "CommonNodeIncludes.h"

class Gate:
public Node,
public HasTrigger,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	Gate();
	
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};
#endif