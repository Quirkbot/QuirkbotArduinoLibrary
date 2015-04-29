#ifndef KeySequence_h_
#define KeySequence_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_SIMULTANEOUS_KEYS 20

class KeySequence :
public Node,
public HasIn<float>,
public HasInterval
{
	public:
	
	KeySequence();

	Input<float> hold;


	protected:
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);

	int scheduleKey[QB_MAX_SIMULTANEOUS_KEYS];
	long scheduleTime[QB_MAX_SIMULTANEOUS_KEYS];
	int index;
};

#endif