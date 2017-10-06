#include "NodeContinuousServo.h"

ContinuousServo::ContinuousServo():
speed(position){
	registerInput(direction);

	direction = 0;
	iddleAngle = 90;
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
	return speed.get() * 90.0 * (direction.get() < 0.5 ? -1 : 1) + 90;
}
void ContinuousServo::onInterval(){
	if(!attached) return;

	if(angle == iddleAngle) {
		detach();
	}
}
