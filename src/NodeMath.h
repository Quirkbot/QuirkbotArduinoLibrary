#ifndef NodeMath_h_
#define NodeMath_h_

#include "CommonNodeIncludes.h"

#define MATH_ADD 0
#define MATH_SUBTRACT 1
#define MATH_MULTIPLY 2
#define MATH_DIVIDE 3
#define MATH_MODULO 4

class Math :
public Node
{
	public:

	Math();
	~Math();

	Input in;
	Input operation;
	Input value;

	Output out;

	protected:

	void onInternalInputChange(BaseInput&);
};
#endif
