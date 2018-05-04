#ifndef NodeConstrain_h_
#define NodeConstrain_h_

#include "CommonNodeIncludes.h"

class Constrain :
public Node
{
	public:

	Constrain();
	~Constrain();

	Input in;
	Input min;
	Input max;

	Output out;

	protected:

	void onInternalInputChange(BaseInput&);
};
#endif
