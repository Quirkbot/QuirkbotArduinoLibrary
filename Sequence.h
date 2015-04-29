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

	Input<float> duration;
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	Input<float> * selected;
	bool running;
	float startTime;

};
#endif