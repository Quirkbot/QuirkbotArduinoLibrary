#ifndef VoltageOutput_h_
#define VoltageOutput_h_

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
