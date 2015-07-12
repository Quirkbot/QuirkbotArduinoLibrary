#ifndef ContinuousServoMotor_h_
#define ContinuousServoMotor_h_

#include "CommonNodeIncludes.h"
#include "ServoMotor.h"

class ContinuousServoMotor:
public ServoMotor {
	public:
	ContinuousServoMotor();
	void onInterval();
};

#endif