#ifndef FilterLowPassFilter_h_
#define FilterLowPassFilter_h_

#include "FilterBase.h"

class FilterLowPass :
public FilterBase
{
	public:

	FilterLowPass();
	~FilterLowPass();

	void push(float number);
};
#endif
