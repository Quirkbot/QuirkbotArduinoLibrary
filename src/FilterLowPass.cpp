#include "FilterLowPass.h"

FilterLowPass::FilterLowPass(){
	value = 0;
	alpha = 0.5;
}
FilterLowPass::~FilterLowPass(){}
void FilterLowPass::push(float number){
	value = value * alpha + number * (1 - alpha);
}
