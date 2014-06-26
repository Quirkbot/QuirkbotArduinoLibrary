#include "Mapping.h"

Mapping::Mapping(){
	registerInput(in);
	registerInput(inMinimum);
	registerInput(inMaximum);
	registerInput(outMinimum);
	registerInput(outMaximum);

	in = 0.0;
	inMinimum = 0.0;
	inMaximum = 1.0;
	outMinimum = 0.0;
	outMaximum = 1.0;
}
void Mapping::onInternalInputChange(BaseInput &input){
	out = Mapping::mapFloat(in, inMinimum, inMaximum, outMinimum, outMaximum);
};


float Mapping::mapFloat(float x, float inMin, float inMax, float outMin, float outMax){
	float result = ((x - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin;
	if(result < outMin) result = outMin;
	else if(result > outMax) result = outMax;
	return result;
}