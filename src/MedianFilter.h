#ifndef MedianFilter_h_
#define MedianFilter_h_

#include "BaseFilter.h"

class MedianFilter :
public BaseFilter 
{
	public:
	
	MedianFilter();
	~MedianFilter();

	void push(float number);

	private:

	float a;
	float b;
	float c;
};
#endif