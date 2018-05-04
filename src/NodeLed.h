#ifndef NodeLed_h_
#define NodeLed_h_

#include "CommonNodeIncludes.h"

class Led :
public InterruptUpdatable,
public Node{
	public:

	Led();
	~Led();

	Input light;
	Input place;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void interruptUpdate();

	volatile uint8_t pwmCompare;
	volatile uint8_t *outPort;
	volatile uint8_t pinMask;
	volatile bool isOn;

	int signalPin;
	volatile int location;
};
#endif
