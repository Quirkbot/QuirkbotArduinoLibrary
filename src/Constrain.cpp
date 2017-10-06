#include "Constrain.h"

Constrain::Constrain():
HasOut
	(this){

	registerInput(in);
	registerInput(min);
	registerInput(max);

	in = 0.0;
	min = 0.0;
	max = 1.0;
};
Constrain::~Constrain(){}
void Constrain::onInternalInputChange(BaseInput &internalInput){
	out.set(Bot::constrain(result, min.get(), max.get()));
};
