#include "ServoMotor.h"

ServoMotor::ServoMotor():
HasInterval
	(this){
	registerInput(position);
	registerInput(place);
	registerInput(iddleTime);

	interval = 0.1;
	position = 0.5;
	place = NO_LOCATION;
	iddleTime = 1.5;

	attached = false;
	angle = -1;
	iddleAngle = -1;
	iddleCount = 0;
};
ServoMotor::~ServoMotor(){}
void ServoMotor::onInternalInputChange(BaseInput &internalInput){

	if(&internalInput == &place){
		if(!attached){
			attach();
		}
		else{
			attach();
			write();
		}
	}
	else if(&internalInput == &position){
		if(!attached){
			attach();
		}
		write();
	}
	else if(&internalInput == &iddleTime){
		iddleLimit = iddleTime.get() / interval.get();
	}

}
void ServoMotor::attach(){
	if(attached) detach();

	attached = true;
	attachedPin = place.get();
	servo.attach(attachedPin);
}
void ServoMotor::detach(){
	attached = false;
	servo.detach();
}
void ServoMotor::write(){
	if(position.get() == -1) return;

	int newAngle = mapAngle();

	if(newAngle != angle){
		angle = newAngle;
		Serial.println(newAngle);
		servo.write(angle);
	}
}
int ServoMotor::mapAngle(){
	return position.get() * 180.0;
}
void ServoMotor::onInterval(){
	if(!attached) return;

	if(iddleAngle == angle) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleLimit) {
		detach();
	}
}
