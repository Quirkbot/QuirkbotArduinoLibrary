#ifndef NodeContinuousServo_h_
#define NodeContinuousServo_h_

#include "CommonNodeIncludes.h"
#include "NodeServoMotor.h"

#define DIRECTION_COUNTER_CLOCKWISE 0
#define DIRECTION_CLOCKWISE 1

class ContinuousServo:
public ServoMotor {
	public:
	ContinuousServo();
	~ContinuousServo();
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);
	int mapMicroseconds();

	Input &speed; // alias to position
	Input direction;
};

#endif
