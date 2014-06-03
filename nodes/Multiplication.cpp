#include "Multiplication.h"

Multiplication::Multiplication(){
	input.setParent(this);
	multiplier.setParent(this);
}

void Multiplication::onParameterUpdated(Parameter& parameter){
	float result = input.getValue() * multiplier.getValue();
	updateOutput(result);
};