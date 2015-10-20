#ifndef LowerFilter_h_
#define LowerFilter_h_

#include "BaseFilter.h"

class LowerFilter :
public BaseFilter
{
	public:

	LowerFilter();
	~LowerFilter();

	void push(float number);

	private:

	float a;
	float b;
	float c;
	float d;
};
#endif
