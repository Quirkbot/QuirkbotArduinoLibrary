#ifndef Multiplication_h_
#define Multiplication_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Multiplication : public BaseNode, public Outputable{
	public:
	
	Multiplication();

	Parameter input;
	Parameter multiplier;

	protected:

	void onParameterUpdated(Parameter& parameter);
};


#endif