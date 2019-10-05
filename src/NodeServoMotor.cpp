#include "NodeServoMotor.h"

ServoMotor::ServoMotor():
HasInterval
	(this){
	registerInput(position);
	registerInput(place);
	registerInput(iddleTime);

	interval = 0.1;
	position = 0.5;
	place = DISCONNECTED;
	iddleTime = 1.5;

	attached = false;
	microseconds = -1;
	iddleMicroseconds = -1;
	iddleCount = 0;
};
ServoMotor::~ServoMotor(){}
void ServoMotor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		attach();
		write();
	}
	else if(&internalInput == &position){
		if(!attached){
			attach();
		}
		write();
	}
	else if(&internalInput == &iddleTime){
		if(interval.get() == 0){
			iddleLimit = 0xFFFF;
		}
		else{
			iddleLimit = iddleTime.get() / interval.get();
		}
	}
}
void ServoMotor::attach(){
	if(attached) detach();

	if(place.get() == DISCONNECTED) return;

	attached = true;
	int attachedPin = place.get();
	servo.attach(attachedPin);
}
void ServoMotor::detach(){
	attached = false;
	servo.detach();
}
void ServoMotor::write(){
	if(!attached) return;

	int newMicroseconds = mapMicroseconds();
	if(newMicroseconds != microseconds){
		microseconds = newMicroseconds;
		servo.writeMicroseconds(microseconds);
	}
}
int ServoMotor::mapMicroseconds(){
	return 600 + position.get() * 1400;
}
void ServoMotor::onInterval(){
	if(!attached) return;

	if(iddleMicroseconds == microseconds) iddleCount++;
	else iddleCount = 0;

	iddleMicroseconds = microseconds;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}
