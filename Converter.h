#ifndef Converter_h_
#define Converter_h_

#include "CommonNodeIncludes.h"

class Converter :
public Node,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	Converter();
	
	InputFloat inMin;
	InputFloat inMax;
	InputFloat outMin;
	InputFloat outMax;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif