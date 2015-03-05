#ifndef ContinuousServoMotor_h_
#define ContinuousServoMotor_h_

#include "CommonNodeIncludes.h"

//#include "_libs_Servo.h"

class ContinuousServoMotor:
public ServoMotor {
	public:

	ContinuousServoMotor(){
		iddleLimit = 1;
	}
	void onInterval();
};


void ContinuousServoMotor::onInterval(){
	if(!attached) return;

	if(angle == 90) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}

#endif
