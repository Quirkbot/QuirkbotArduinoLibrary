#ifndef ServoMotor_h_
#define ServoMotor_h_

#include "CommonNodeIncludes.h"

#include "Servo.h"

class ServoMotor:
public Node,
public HasInterval{
	public:

	ServoMotor();
	~ServoMotor();

	Input position;
	Input place;
	Input iddleTime;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
	void onInterval();

	void attach();
	void detach();
	void write();
	int mapAngle();

	Servo servo;
	int angle;

	int attachedPin;
	bool attached;
	int iddleAngle;
	int iddleCount;
	int iddleLimit;
};

#endif
