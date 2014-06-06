#ifndef Sine_h_
#define Sine_h_

#include <math.h>

#include "Node.h"
#include "Input.h"
#include "Output.h"


class Sine : public Node{
	public:
	
	Sine();

	Input source;
	Output result;

	protected:

	void onInternalInputChange(Input &input);
	void onSourceChange();
};

#endif
