#ifndef Converter_h_
#define Converter_h_

#include "CommonNodeIncludes.h"

class Converter :
public Node,
public HasIn,
public HasOut
{
	public:
	
	Converter();
	~Converter();
	
	Input inMin;
	Input inMax;
	Input outMin;
	Input outMax;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif