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

		interval = 0.5;

		attached = false;
		angle = -1;		
		iddleAngle = -1;
		iddleCount = 0;	
		iddleMaxTime = 3;			
	};

	Input<int> pin;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
	void onInterval();

	void attach();
	void detach();
	void write();

	_libs_Servo servo;
	int angle;
	
	int attachedPin;
	bool attached;
	int iddleAngle;
	int iddleCount;
	int iddleMaxTime;
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

	int newAngle = in.get() * 180.0;
	if(newAngle != angle){
		angle = newAngle;
		servo.write(angle);
	}
}
void ServoMotor::onInterval(){
	if(!attached) return;

	if(iddleAngle == angle) iddleCount++;
	else iddleCount = 0;

	iddleAngle = angle;

	if(iddleCount >= iddleMaxTime) {
		detach();
	}
}

#endif
