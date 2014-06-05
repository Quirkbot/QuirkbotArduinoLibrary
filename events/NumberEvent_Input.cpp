#include "events/NumberEvent_Input.h"

void NumberEvent_Input::add(Input* input, NumberEventHandler_Input handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	inputs.push_back(input);
	handlers.push_back(handler);
}
void NumberEvent_Input::remove(NumberEventHandler_Input handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	inputs.erase (inputs.begin()+position);
	handlers.erase (handlers.begin()+position);
}
void NumberEvent_Input::dispatch(float value){
	for(int i=0; i<handlers.size(); i++){
		(inputs[i]->*(handlers[i]))(value);
	}
}
int NumberEvent_Input::handlerPosition(NumberEventHandler_Input handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}