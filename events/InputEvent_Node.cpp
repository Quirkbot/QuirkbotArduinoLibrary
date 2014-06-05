#include "events/InputEvent_Node.h"

void InputEvent_Node::add(Node* input, InputEventHandler_Node handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	inputs.push_back(input);
	handlers.push_back(handler);
}
void InputEvent_Node::remove(InputEventHandler_Node handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	inputs.erase (inputs.begin()+position);
	handlers.erase (handlers.begin()+position);
}
void InputEvent_Node::dispatch(Input& value){
	for(int i=0; i<handlers.size(); i++){
		(inputs[i]->*(handlers[i]))(value);
	}
}
int InputEvent_Node::handlerPosition(InputEventHandler_Node handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}