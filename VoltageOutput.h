#ifndef VoltageOutput_h_
#define VoltageOutput_h_

#include "CommonNodeIncludes.h"

class VoltageOutput :
public Updatable,
public Node,
public HasIn{
	public:
	
	VoltageOutput();
	~VoltageOutput();

	Input place;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	bool useSoftPWM;
	int pwmWidth;
	unsigned int pwmOffset;
	volatile uint8_t *outPort;
	uint8_t pinMask;
	int signalPin;
	int location;

};
#endif