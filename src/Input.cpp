#include "Input.h"

Input::Input(){
	node = NULL;
	output = NULL;

	// A crazy initial value, so when onOutputChange is called for the first
	// time with a real value, it won't clash and  be forwarded to
	// node->onInternalInputChange
	value = -12345.67890;
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
	onOutputChange(this->output->get());
}
void Input::onOutputChange(float value){
	if(this->value == value) {
		return;
	}
	this->value = value;
	if(node != NULL){
		node->onInternalInputChange(*this);
	}
}
void Input::clearOutput(){
	if(output){
		output->event.remove(&Input::onOutputChange);
		output = NULL;
	}
}
