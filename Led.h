#ifndef Led_h_
#define Led_h_

#include "CommonNodeIncludes.h"

class Led :
public Updatable,
public Node,
public HasIn<float>{
	public:
	
	Led();

	InputFloat place;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
	void update();
	void serialReport();

	bool useSoftPWM;
	int pwmWidth;
	unsigned int pwmOffset;
	volatile uint8_t *outPort;
	uint8_t pinMask;

	int signalPin;

	int location;	

};
#endif