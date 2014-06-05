#include "Input.h"

Input::Input(){
}
Input::~Input(){
	clearOutput();
}
void Input::connect(const float &number){
	clearOutput();
	onOutputChange(number);
}
void Input::connect(Output &output){
	clearOutput();
	this->output = &output;
	this->output->changed->add(this, &Input::onOutputChange);
}
Input& Input::operator=(const float &number){
	connect(number);
}
Input& Input::operator=(Output &output){
	connect(output);
}
Input::operator float(){
	return value;
}
float Input::get(){
	return value;
}
void Input::onOutputChange(float value){
	this->value = value;
	node->onInternalInputChange(*this);
}
void Input::clearOutput(){
	if(output)
		output->changed->remove(&Input::onOutputChange);
}

