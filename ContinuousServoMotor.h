#ifndef ContinuousServoMotor_h_
#define ContinuousServoMotor_h_

#include "CommonNodeIncludes.h"

class ContinuousServoMotor:
public Servo{
	public:
	
	ContinuousServoMotor(){
		attached = true;
	};

	protected:

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
	servo.dettach();
	attached = false;
}

#endif
