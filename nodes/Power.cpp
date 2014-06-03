#include "Power.h"

Power::Power(){
	input.setParent(this);
	exponent.setParent(this);
}

void Power::onParameterUpdated(Parameter& parameter){
	float result = pow(input.getValue(), exponent.getValue());
	updateOutput(result);
};