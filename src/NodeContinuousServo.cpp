#include "NodeContinuousServo.h"

ContinuousServo::ContinuousServo():
speed(position){
	registerInput(direction);

	direction = DIRECTION_COUNTER_CLOCKWISE;
	iddleMicroseconds = 1300;
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
int ContinuousServo::mapMicroseconds(){
	if (direction.get() < 0.5) {
		return iddleMicroseconds - 125 - speed.get() * 375;
	}
	return iddleMicroseconds + 125 + speed.get() * 375;
}
void ContinuousServo::onInterval(){
	if(!attached) return;

	if(microseconds >= iddleMicroseconds - 125 && microseconds <= iddleMicroseconds + 125) {
		detach();
	}
}
