#ifndef UpperFilter_h_
#define UpperFilter_h_

#include "BaseFilter.h"

class UpperFilter :
public BaseFilter 
{
	public:
	
	UpperFilter();
	~UpperFilter();

	void push(float number);

	private:

	float a;
	float b;
	float c;
	float d;
};
#endif