#ifndef FilterMedian_h_
#define FilterMedian_h_

#include "FilterBase.h"

class FilterMedian :
public FilterBase
{
	public:

	FilterMedian();
	~FilterMedian();

	void push(float number);

	private:

	float a;
	float b;
	float c;
};
#endif
