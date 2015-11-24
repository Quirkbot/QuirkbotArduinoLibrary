#ifndef LowPassFilter_h_
#define LowPassFilter_h_

#include "BaseFilter.h"

class LowPassFilter :
public BaseFilter
{
	public:

	LowPassFilter();
	~LowPassFilter();

	void push(float number);
};
#endif
