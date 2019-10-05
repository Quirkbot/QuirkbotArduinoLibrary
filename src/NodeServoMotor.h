#ifndef NodeServoMotor_h_
#define NodeServoMotor_h_

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

	virtual void onInternalInputChange(BaseInput &internalInput);
	void onInterval();

	void attach();
	void detach();
	void write();
	virtual int mapMicroseconds();

	Servo servo;
	int microseconds;

	bool attached;
	int iddleMicroseconds;
	int iddleCount;
	int iddleLimit;
};

#endif
