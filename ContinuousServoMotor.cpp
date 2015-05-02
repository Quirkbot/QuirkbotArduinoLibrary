#include "ContinuousServoMotor.h"

ContinuousServoMotor::ContinuousServoMotor(){
	iddleTime = 0.1;
}
ContinuousServoMotor::~ContinuousServoMotor(){}
void ContinuousServoMotor::onInterval(){
	if(!attached) return;

	if(angle == 90) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}