#ifndef Sequence_h_
#define Sequence_h_

#include "CommonNodeIncludes.h"

class Sequence:
public Node,
public HasInterval,
public HasInputCollection,
public HasTrigger,
public HasOut
{
	public:

	Sequence();
	~Sequence();

	void onInterval();

	Input duration;
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	Input * selected;
	bool running;
	float startTime;

};
#endif