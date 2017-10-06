#ifndef NodeMath_h_
#define NodeMath_h_

#include "CommonNodeIncludes.h"

#define MATH_ADD 0
#define MATH_SUBTRACT 1
#define MATH_MULTIPLY 2
#define MATH_DIVIDE 3

class Math :
public Node,
public HasOut
{
	public:

	Math();
	~Math();

	Input in;
	Input operation;
	Input value;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
