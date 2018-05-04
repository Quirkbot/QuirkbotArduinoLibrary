#include "Event.h"

Event::Event(){}
Event::~Event(){}
void Event::add(Input* input, TypedInputHandler handler){
	int pos = position(input, handler);
	if(pos != -1) return;
	typedInputs.push(input);
	typedInputHandlers.push(handler);
}
void Event::remove(Input* input, TypedInputHandler handler){
	int pos = position(input, handler);
	if(pos == -1) return;
	typedInputs.erase(pos);
	typedInputHandlers.erase(pos);
}
int Event::position(Input* input, TypedInputHandler handler){
	for(unsigned int i=0; i<typedInputHandlers.size(); i++){
		if(typedInputs[i] == input && typedInputHandlers[i] == handler) {
			return i;
		}
	}
	return -1;
}
void Event::dispatch(float &value){
	for(unsigned int i=0; i<typedInputHandlers.size(); i++){
		(typedInputs[i]->*(typedInputHandlers[i]))(value);
	}
}
