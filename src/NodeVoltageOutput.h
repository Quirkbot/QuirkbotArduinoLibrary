#ifndef NodeVoltageOutput_h_
#define NodeVoltageOutput_h_

#include "CommonNodeIncludes.h"
#include "Led.h"

class VoltageOutput :
public Led{
	public:

	VoltageOutput();
	~VoltageOutput();

	Input &in; // alias to light

};

#endif
