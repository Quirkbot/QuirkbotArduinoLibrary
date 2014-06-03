#include "Operation.h"

Operation::Operation(){
	input.setParent(this);
}

void Operation::onParameterUpdated(Parameter& parameter){
	float result = function(input.getValue());
	updateOutput(result);
};