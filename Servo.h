#ifndef Servo_h_
#define Servo_h_

#include "Arduino.h"
#include "_libs_Servo.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Streams.h"

class Servo:
public Node,
public InputStream<float>{
	public:
	
	Servo():
	InputStream<float>
		(position){

		registerInput(pin);
		registerInput(position);

		position = 0;
		angle = -1;
		
	};

	Input<int> pin;
	Input<float> position;

	protected:

	void onInternalInputChange(BaseInput &input);

	_libs_Servo servo;
	int angle;
};
void Servo::onInternalInputChange(BaseInput &input){
	if(&input == &pin){
		servo.attach(pin);
	}
	else if(&input == &position){
		int newAngle = position * 180.0;
		if(newAngle != angle){
			angle = newAngle;
			servo.write(angle);
		}		
	}
}

#endif
