#include "OutputFloat.h"

OutputFloat::OutputFloat(){
	value = 0;
}
OutputFloat::~OutputFloat(){
}
void OutputFloat::connect(InputFloat &input){
	input.connect(*this);
}
void OutputFloat::set(float value){
	if(this->value == value) return;
	this->value = value;
	event.dispatch(value);
}
float OutputFloat::get(){
	return value;
}