#ifndef NodeLogic_h_
#define NodeLogic_h_

#include "CommonNodeIncludes.h"

#define LOGIC_AND 0
#define LOGIC_OR 1
#define LOGIC_XOR 2

class Logic :
public Node,
public HasOut
{
	public:

	Logic();
	~Logic();

	Input operation;
	InputCollection items;
	Input min;
	Input max;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
