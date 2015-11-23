#include "ContinuousServo.h"

ContinuousServo::ContinuousServo():
speed(position){
	registerInput(direction);

	direction = 0;
	iddleTime = 0.1;
}
ContinuousServo::~ContinuousServo(){}
void ContinuousServo::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &direction){
		if(!attached){
			attach();
		}
		write();
	}
	else{
		ServoMotor::onInternalInputChange(internalInput);
	}
}
int ContinuousServo::mapAngle(){
	Serial.println(speed.get() * 90.0 * (direction.get() < 0.5 ? -1 : 1) + 90);
	return speed.get() * 90.0 * (direction.get() < 0.5 ? -1 : 1) + 90;
}
void ContinuousServo::onInterval(){
	if(!attached) return;

	if(angle == 90) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}
