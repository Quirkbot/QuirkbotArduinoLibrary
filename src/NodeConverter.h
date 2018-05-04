#ifndef NodeConverter_h_
#define NodeConverter_h_

#include "CommonNodeIncludes.h"

class Converter :
public Node
{
	public:

	Converter();
	~Converter();

	Input in;
	Input inMin;
	Input inMax;
	Input outMin;
	Input outMax;

	Output out;

	protected:

	void onInternalInputChange(BaseInput&);
};
#endif
