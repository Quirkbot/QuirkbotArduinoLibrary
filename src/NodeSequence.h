#ifndef NodeSequence_h_
#define NodeSequence_h_

#include "CommonNodeIncludes.h"

class Sequence:
public Node,
public HasInterval,
public HasTrigger
{
	public:

	Sequence();
	~Sequence();

	void onInterval();

	Input duration;
	InputCollection items;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	Input * selected;
	bool running;
	float startTime;

};
#endif
