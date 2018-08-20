#include "Event.h"

Event::Event(){}
Event::~Event(){}
void Event::add(Input* input, InputHandler handler){
	int pos = position(input, handler);
	if(pos != -1) return;
	inputs.add(input);
	handlers.add(handler);
}
void Event::remove(Input* input, InputHandler handler){
	int pos = position(input, handler);
	if(pos == -1) return;
	inputs.removeAt(pos);
	handlers.removeAt(pos);
}
int Event::position(Input* input, InputHandler handler){
	for(unsigned int i=0; i<handlers.size(); i++){
		if(inputs[i] == input && handlers[i] == handler) {
			return i;
		}
	}
	return -1;
}
void Event::dispatch(float &value){
	for(unsigned int i=0; i<handlers.size(); i++){
		(inputs[i]->*(handlers[i]))(value);
	}
}
