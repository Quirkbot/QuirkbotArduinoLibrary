#include "Sine.h"

Sine::Sine(){
	input.setParent(this);
}

void Sine::onParameterUpdated(Parameter& parameter){
	updateOutput(sin(parameter.getValue()));
};