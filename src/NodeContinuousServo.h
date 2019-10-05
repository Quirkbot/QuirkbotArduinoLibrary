#ifndef NodeContinuousServo_h_
#define NodeContinuousServo_h_

#include "CommonNodeIncludes.h"
#include "NodeServoMotor.h"

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
