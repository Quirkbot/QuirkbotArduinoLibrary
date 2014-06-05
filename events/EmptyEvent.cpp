#include "events/EmptyEvent.h"

void EmptyEvent::add(EmptyEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	handlers.push_back(handler);
}
void EmptyEvent::remove(EmptyEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	handlers.erase (handlers.begin()+position);
}
void EmptyEvent::dispatch(){
	for(int i=0; i<handlers.size(); i++){
		handlers[i]();
	}
}
int EmptyEvent::handlerPosition(EmptyEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}