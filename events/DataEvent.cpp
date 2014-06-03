#include "events/DataEvent.h"

void DataEvent::add(DataEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	handlers.push_back(handler);
}
void DataEvent::remove(DataEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	handlers.erase (handlers.begin()+position);
}
void DataEvent::dispatch(void* data){
	for(int i=0; i<handlers.size(); i++){
		handlers[i](data);
	}
}
int DataEvent::handlerPosition(DataEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}