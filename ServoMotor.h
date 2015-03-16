#ifndef ServoMotor_h_
#define ServoMotor_h_

#include "CommonNodeIncludes.h"

#include "_libs_Servo.h"

class ServoMotor:
public Node,
public HasInterval,
public HasIn<float>{
	public:
	
	ServoMotor():
	HasInterval
		(this),
	HasIn<float>
		(this){
		registerInput(pin);
		registerInput(iddleTime);

		interval = 0.1;
		iddleTime = 1.5;

		attached = false;
		angle = -1;		
		iddleAngle = -1;
		iddleCount = 0;			
	};

	Input<int> pin;
	Input<float> iddleTime;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
	void onInterval();

	void attach();
	void detach();
	void write();
	int mapAngle();

	_libs_Servo servo;
	int angle;
	
	int attachedPin;
	bool attached;
	int iddleAngle;
	int iddleCount;
	int iddleLimit;
};
void ServoMotor::onInternalInputChange(BaseInput &internalInput){

	if(&internalInput == &pin){
		if(!attached){
			attach();
		}
		else{
			attach();
			write();
		}
	}
	else if(&internalInput == &in){
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
	attachedPin = pin.get();
	servo.attach(attachedPin);
}
void ServoMotor::detach(){
	attached = false;
	servo.detach();
}
void ServoMotor::write(){
	if(in.get() == -1) return;

	int newAngle = mapAngle();
	if(newAngle != angle){
		angle = newAngle;
		servo.write(angle);
	}
}
int ServoMotor::mapAngle(){
	return in.get() * 180.0;
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

#endif
