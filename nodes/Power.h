#ifndef Power_h_
#define Power_h_

#include <math.h>

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Power : public BaseNode, public Outputable{
	public:
	
	Power();

	Parameter input;
	Parameter exponent;

	protected:

	void onParameterUpdated(Parameter& parameter);
};


#endif
