#include "events/ValueEvent.h"

void ValueEvent::add(ValueEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	handlers.push_back(handler);
}
void ValueEvent::remove(ValueEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	handlers.erase (handlers.begin()+position);
}
void ValueEvent::dispatch(float value){
	for(int i=0; i<handlers.size(); i++){
		handlers[i](value);
	}
}
int ValueEvent::handlerPosition(ValueEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}