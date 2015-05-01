#ifndef DualColorLed_h_
#define DualColorLed_h_

#include "CommonNodeIncludes.h"

class DualColorLed :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	DualColorLed();

	InputFloat place;
	InputFloat color;
	

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();

	int pwmWidth;
	
	unsigned int pwmOffset;
	unsigned int pwmOffsetFront;
	unsigned int pwmOffsetBack;
	
	int frontPin;
	volatile uint8_t *outPortFront;
	uint8_t pinMaskFront;

	int backPin;
	volatile uint8_t *outPortBack;
	uint8_t pinMaskBack;

	bool active;

	int location;

};
#endif