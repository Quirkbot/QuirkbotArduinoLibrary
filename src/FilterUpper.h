#ifndef FilterUpper_h_
#define FilterUpper_h_

#include "FilterBase.h"

class FilterUpper :
public FilterBase
{
	public:

	FilterUpper();
	~FilterUpper();

	void push(float number);

	private:

	float a;
	float b;
	float c;
	float d;
};
#endif
