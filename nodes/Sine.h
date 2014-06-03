#ifndef Sine_h_
#define Sine_h_

#include <math.h>

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Sine : public BaseNode, public Outputable{
	public:
	
	Sine();

	Parameter input;

	protected:

	void onParameterUpdated(Parameter& parameter);
};


#endif
