#ifndef NodeComparison_h_
#define NodeComparison_h_

#include "CommonNodeIncludes.h"

#define COMP_EQUAL 0
#define COMP_DIFF 1
#define COMP_GREATER 2
#define COMP_GREATER_EQUAL 3
#define COMP_LESS 4
#define COMP_LESS_EQUAL 5

class Comparison :
public Node
{
	public:

	Comparison();
	~Comparison();

	Input in;
	Input operation;
	Input value;
	Input min;
	Input max;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif
