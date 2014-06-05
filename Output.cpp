#include "Output.h"

Output::Output(){
	changed = new NumberEvent_Input();
	value = 0;
}
Output::~Output(){
	delete changed;
}
float Output::get(){
	return value;
}
Output::operator float(){
	return value;
}
void Output::set(float value){
	if(this->value == value) return;
	this->value = value;
	changed->dispatch(value);
}