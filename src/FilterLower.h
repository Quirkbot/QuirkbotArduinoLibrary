#ifndef FilterLower_h_
#define FilterLower_h_

#include "FilterBase.h"

class FilterLower :
public FilterBase
{
	public:

	FilterLower();
	~FilterLower();

	void push(float number);

	private:

	float a;
	float b;
	float c;
	float d;
};
#endif
