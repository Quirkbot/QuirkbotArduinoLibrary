#include "FilterBase.h"

FilterBase::FilterBase(){}
FilterBase::~FilterBase(){}
float FilterBase::get(){
	return value;
}
void FilterBase::set(float v){
	value = v;
}
