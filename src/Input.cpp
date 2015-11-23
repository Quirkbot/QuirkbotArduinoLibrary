#include "Input.h"

Input::Input(){
	output = NULL;
	value = 0;
}
Input::~Input(){
	clearOutput();
}
void Input::operator=(const float &value){
	handleValueConnection(value);
}
void Input::connect(const Output &output){
	handleOutputConnection(output);
}
void Input::disconnect(){
	clearOutput();
}
float Input::get(){
	return value;
}
void Input::handleValueConnection(const float &value){
	/**
	 * Should value connections really clear the output? Maybe it's better
	 * if they keep the connection, so we know that every time we connect to
	 * an output, the only way to disconnect is by explicitly calling the
	 * 'disconnect' method.
	 **/
	clearOutput();
	onOutputChange(value);
}
void Input::handleOutputConnection(const Output &output){
	clearOutput();
	this->output = (Output*) &output;
	this->output->event.add(this, &Input::onOutputChange);
}
void Input::onOutputChange(float value){
	this->value = value;
	if(node) node->onInternalInputChange(*this);
}
void Input::clearOutput(){
	if(output){
		output->event.remove(&Input::onOutputChange);
		output = NULL;
	}
}
