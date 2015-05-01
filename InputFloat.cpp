#include "InputFloat.h"

InputFloat::InputFloat(){
	output = NULL;
	value = 0;
}
InputFloat::~InputFloat(){
	clearOutput();
}
void InputFloat::operator=(const float &value){
	handleValueConnection(value);
}
void InputFloat::connect(const OutputFloat &output){
	handleOutputConnection(output);
}
void InputFloat::disconnect(){
	clearOutput();
}
float InputFloat::get(){
	return value;
}
void InputFloat::handleValueConnection(const float &value){
	/**
	 * Should value connections really clear the output? Maybe it's better
	 * if they keep the connection, so we know that every time we connect to
	 * an output, the only way to disconnect is by explicitly calling the 
	 * 'disconnect' method.
	 **/
	clearOutput();
	onOutputChange(value);
}
void InputFloat::handleOutputConnection(const OutputFloat &output){
	clearOutput();
	this->output = (OutputFloat*) &output;
	this->output->event.add(this, &InputFloat::onOutputChange);
}
void InputFloat::onOutputChange(float value){
	this->value = value;
	if(node) node->onInternalInputChange(*this);
}
void InputFloat::clearOutput(){
	if(output){
		output->event.remove(&InputFloat::onOutputChange);
		output = NULL;
	}
}