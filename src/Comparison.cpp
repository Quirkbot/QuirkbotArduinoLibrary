#include "Comparison.h"

Comparison::Comparison():
HasOut
	(this){

	registerInput(in);
	registerInput(operation);
	registerInput(value);
	registerInput(min);
	registerInput(max);

	in = 0.0;
	operation = COMP_EQUAL;
	value = 0.0;
	min = 0.0;
	max = 1.0;
};
Comparison::~Comparison(){}
void Comparison::onInternalInputChange(BaseInput &internalInput){
	bool result;

	if (operation.get() == COMP_EQUAL) {
		result = in.get() == value.get();
	}
	else if (operation.get() == COMP_DIFF) {
		result = in.get() != value.get();
	}
	else if (operation.get() == COMP_GREATER) {
		result = in.get() > value.get();
	}
	else if (operation.get() == COMP_GREATER_EQUAL) {
		result = in.get() >= value.get();
	}
	else if (operation.get() == COMP_LESS) {
		result = in.get() < value.get();
	}
	else if (operation.get() == COMP_LESS_EQUAL) {
		result = in.get() <= value.get();
	}

	out.set(result ? max.get() : min.get());
};
