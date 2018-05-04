#include "NodeConverter.h"

Converter::Converter(){

	registerInput(in);
	registerInput(inMin);
	registerInput(inMax);
	registerInput(outMin);
	registerInput(outMax);

	in = 0.0;
	inMin = 0.0;
	inMax = 1.0;
	outMin = 0.0;
	outMax = 1.0;
};
Converter::~Converter(){}
void Converter::onInternalInputChange(BaseInput &internalInput){
	out.set(
		Bot::map(
			in.get(),
			inMin.get(),
			inMax.get(),
			outMin.get(),
			outMax.get()
		)
	);
};
