#ifndef NodeKeySequence_h_
#define NodeKeySequence_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_SIMULTANEOUS_KEYS 20

class KeySequence :
public Node,
public HasInterval
{
	public:

	KeySequence();
	~KeySequence();

	Input key;
	Input holdTime;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void onInterval();

	unsigned int scheduleKey[QB_MAX_SIMULTANEOUS_KEYS];
	unsigned long scheduleTime[QB_MAX_SIMULTANEOUS_KEYS];
	unsigned int index;
};

#endif
