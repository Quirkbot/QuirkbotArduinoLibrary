#ifndef ContinuousServo_h_
#define ContinuousServo_h_

#include "CommonNodeIncludes.h"
#include "ServoMotor.h"

class ContinuousServo:
public ServoMotor {
	public:
	ContinuousServo();
	~ContinuousServo();
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);
	int mapAngle();

	Input &speed; // alias to position
	Input direction;
};

#endif
