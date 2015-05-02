#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(){
	value = 0;
	alpha = 0.5;
}
void LowPassFilter::push(float number){
	value = value * alpha + number * (1 - alpha);
}