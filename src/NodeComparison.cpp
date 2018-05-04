#include "NodeComparison.h"

Comparison::Comparison(){

	registerInput(in);
	registerInput(operation);
	registerInput(value);
	registerInput(valueThen);
	registerInput(valueElse);

	in = 0.0;
	operation = COMP_EQUAL;
	value = 0.0;
	valueThen = 1.0;
	valueElse = 0.0;
};
Comparison::~Comparison(){}
void Comparison::onInternalInputChange(BaseInput&){
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
	else if (operation.get() == COMP_GREATER_EQ) {
		result = in.get() >= value.get();
	}
	else if (operation.get() == COMP_LESS) {
		result = in.get() < value.get();
	}
	else if (operation.get() == COMP_LESS_EQ) {
		result = in.get() <= value.get();
	}

	out.set(result ? valueThen.get() : valueElse.get());
};
