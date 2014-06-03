#include "events/SimpleEvent.h"

void SimpleEvent::add(SimpleEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	handlers.push_back(handler);
}
void SimpleEvent::remove(SimpleEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	handlers.erase (handlers.begin()+position);
}
void SimpleEvent::dispatch(){
	for(int i=0; i<handlers.size(); i++){
		handlers[i]();
	}
}
int SimpleEvent::handlerPosition(SimpleEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}