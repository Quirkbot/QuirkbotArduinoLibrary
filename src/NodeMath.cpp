#include "NodeMath.h"

Math::Math():
HasOut
	(this){

	registerInput(in);
	registerInput(operation);
	registerInput(value);

	in = 0.0;
	operation = MATH_ADD;
	value = 0.0;
};
Math::~Math(){}
void Math::onInternalInputChange(BaseInput &internalInput){
	if(operation.get() == MATH_ADD) {
		out.set(in.get() + value.get());
		return;
	}

	if(operation.get() == MATH_SUBTRACT) {
		out.set(in.get() - value.get());
		return;
	}

	if(operation.get() == MATH_MULTIPLY) {
		out.set(in.get() * value.get());
		return;
	}

	if(operation.get() == MATH_DIVIDE && value.get() != 0) {
		if(value.get() == 0) {
			out.set(0);
			return;
		}
		out.set(in.get() / value.get());
		return;
	}
};