#ifndef ServoMotor_h_
#define ServoMotor_h_

#include "CommonNodeIncludes.h"

#include "_libs_Servo.h"

class ServoMotor:
public Node,
public HasIn<float>{
	public:
	
	ServoMotor():
	HasIn<float>
		(this){

		registerInput(pin);

		angle = -1;		
	};

	Input<int> pin;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	_libs_Servo servo;
	int angle;
};
void ServoMotor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin){
		servo.attach(pin.get());
	}
	else if(&internalInput == &in){
		int newAngle = in.get() * 180.0;
		if(newAngle != angle){
			angle = newAngle;
			servo.write(angle);
		}		
	}
}

#endif
