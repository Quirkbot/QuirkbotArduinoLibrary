#ifndef IRProximity_h_
#define IRProximity_h_

#include "CommonNodeIncludes.h"

#define QB_IR_PROXIMITY_OUTPUT_PIN BP1
#define QB_IR_PROXIMITY_INPUT_PIN BP2
#define QB_IR_PROXIMITY_MAX 512

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

	uint8_t *outputPort;
	uint8_t outputMask;

	bool readingFlag;
	unsigned int readingA;
	unsigned int readingB;
};
#endif
