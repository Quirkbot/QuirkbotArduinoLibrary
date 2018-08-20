#include "FilterLowPass.h"

FilterLowPass::FilterLowPass(){
	value = 0;
	factor = 0.5;
}
FilterLowPass::~FilterLowPass(){}
void FilterLowPass::push(float number){
	value = value * factor + number * (1 - factor);
}
