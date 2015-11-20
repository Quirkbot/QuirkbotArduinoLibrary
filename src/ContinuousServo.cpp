#include "ContinuousServo.h"

ContinuousServo::ContinuousServo(){
	iddleTime = 0.1;
}
ContinuousServo::~ContinuousServo(){}
void ContinuousServo::onInterval(){
	if(!attached) return;

	if(angle == 90) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}
