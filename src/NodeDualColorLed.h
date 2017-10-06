#ifndef NodeDualColorLed_h_
#define NodeDualColorLed_h_

#include "CommonNodeIncludes.h"

class DualColorLed :
public InterruptUpdatable,
public Node {
	public:

	DualColorLed();
	~DualColorLed();

	Input place;
	Input light;
	Input color;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	volatile void interruptUpdate();

	int frontPin;
	volatile uint8_t pwmStartFront;
	volatile uint8_t pwmEndFront;
	volatile uint8_t *outPortFront;
	volatile uint8_t pinMaskFront;
	volatile bool isOnFront;

	int backPin;
	volatile uint8_t pwmStartBack;
	volatile uint8_t pwmEndBack;
	volatile uint8_t *outPortBack;
	volatile uint8_t pinMaskBack;
	volatile bool isOnBack;

	volatile bool active;

	int location;

};
#endif
