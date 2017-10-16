#ifndef NodeConstrain_h_
#define NodeConstrain_h_

#include "CommonNodeIncludes.h"

class Constrain :
public Node,
public HasOut
{
	public:

	Constrain();
	~Constrain();

	Input in;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
