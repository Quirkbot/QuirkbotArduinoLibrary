#include "Output.h"

Output::Output(){
	value = 0;
}
Output::~Output(){
}
void Output::connect(Input &input){
	input.connect(*this);
}
void Output::set(float value){
	this->value = value;
	event.dispatch(value);
}
float Output::get(){
	return value;
}
