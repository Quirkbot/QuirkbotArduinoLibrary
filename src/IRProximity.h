#ifndef IRProximity_h_
#define IRProximity_h_

#include "CommonNodeIncludes.h"

#define QB_IR_PROXIMITY_OUTPUT_PIN BP4
#define QB_IR_PROXIMITY_INPUT_PIN BP2
#define QB_IR_PROXIMITY_MAX 120

class IRProximity :
public Node,
public HasInterval,
public HasOut
{
	public:

	IRProximity();
	~IRProximity();

	void onInterval();

	Input min;
	Input max;

	protected:

	MedianFilter filter;
	LowPassFilter lowpass;

	volatile uint8_t *outputPort;
	uint8_t outputMask;
	uint8_t readPin;

	bool readingFlag;
	unsigned int readingA;
	unsigned int readingB;
};
#endif
