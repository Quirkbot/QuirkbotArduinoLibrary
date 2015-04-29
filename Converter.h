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
	
	Input<float> inMin;
	Input<float> inMax;
	Input<float> outMin;
	Input<float> outMax;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
#endif