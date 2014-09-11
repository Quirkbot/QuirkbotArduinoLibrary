#ifndef ServoMotor_h_
#define ServoMotor_h_

#include "Arduino.h"
#include "_libs_Servo.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Streams.h"

class ServoMotor:
public Node,
public InputStream<float>{
	public:
	
	ServoMotor():
	InputStream<float>
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
