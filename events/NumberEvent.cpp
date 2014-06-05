#include "events/NumberEvent.h"

void NumberEvent::add(NumberEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	handlers.push_back(handler);
}
void NumberEvent::remove(NumberEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	handlers.erase (handlers.begin()+position);
}
void NumberEvent::dispatch(const float value){
	for(int i=0; i<handlers.size(); i++){
		handlers[i](value);
	}
}
int NumberEvent::handlerPosition(NumberEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}