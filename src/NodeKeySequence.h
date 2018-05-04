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
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);

	unsigned int scheduleKey[QB_MAX_SIMULTANEOUS_KEYS];
	unsigned long scheduleTime[QB_MAX_SIMULTANEOUS_KEYS];
	unsigned int index;
};

#endif
