#ifndef ContinuousServoMotor_h_
#define ContinuousServoMotor_h_

#include "CommonNodeIncludes.h"

#include "_libs_Servo.h"

class ContinuousServoMotor:
public Node,
public HasIn<float>{
	public:
	
	ContinuousServoMotor():
	HasIn<float>
		(this){
		registerInput(pin);
		angle = -1;		
		attached = true;
	};

	Input<int> pin;
	Input<float> in;
	protected:

	_libs_Servo servo;
	int angle;

	bool attached;

	void attachServo();
	void dettachServo();
	void onInternalInputChange(BaseInput &internalInput);
};
void ContinuousServoMotor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin){
		attachServo();
	}
	else if(&internalInput == &in){
		if(!attached) attachServo();

		int newAngle = (in.get() + 1.0) * 0.5 * 180.0;

		if(newAngle != angle){
			angle = newAngle;
			if(!angle) dettachServo();
			else servo.write(angle);
		}
	}
}
void ContinuousServoMotor::attachServo(){
	servo.attach(pin.get());
	attached = true;
}
void ContinuousServoMotor::dettachServo(){
	servo.detach();
	attached = false;
}

#endif
