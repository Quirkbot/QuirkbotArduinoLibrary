#ifndef Operation_h_
#define Operation_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Operation : public BaseNode, public Outputable{
	public:

	typedef float (*OperationFunction)(float);
	
	Operation();

	Parameter input;
	OperationFunction function;

	protected:

	void onParameterUpdated(Parameter& parameter);
};


#endif