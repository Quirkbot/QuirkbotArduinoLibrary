#ifndef Sequence_h_
#define Sequence_h_

#include "CommonNodeIncludes.h"

class Sequence:
public Node,
public HasInterval,
public HasInputCollection<float>,
public HasTrigger,
public HasOut<float>
{
	public:
	
	Sequence();

	void onInterval();

	InputFloat duration;
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	InputFloat * selected;
	bool running;
	float startTime;

};
#endif