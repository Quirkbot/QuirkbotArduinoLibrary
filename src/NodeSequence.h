#ifndef NodeSequence_h_
#define NodeSequence_h_

#include "CommonNodeIncludes.h"

class Sequence:
public Node,
public HasInterval,
public HasTrigger,
public HasOut
{
	public:

	Sequence();
	~Sequence();

	void onInterval();

	Input duration;
	InputCollection items;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	Input * selected;
	bool running;
	float startTime;

};
#endif
