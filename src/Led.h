#ifndef Led_h_
#define Led_h_

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
	volatile void interruptUpdate();
	void serialReport();

	volatile uint8_t pwmCompare;
	volatile uint8_t *outPort;
	volatile uint8_t pinMask;
	volatile bool isOn;

	int signalPin;
	volatile int location;
};
#endif
