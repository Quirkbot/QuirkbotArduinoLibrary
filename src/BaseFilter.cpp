#include "BaseFilter.h"

BaseFilter::BaseFilter(){}
BaseFilter::~BaseFilter(){}
float BaseFilter::get(){
	return value;
}
void BaseFilter::set(float v){
	value = v;
}
