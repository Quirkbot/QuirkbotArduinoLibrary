#include "events/OutputUpdateEvent.h"

void OutputUpdateEvent::add(Parameter* parameter, OutputUpdateEventHandler handler){
	int position = handlerPosition(handler);
	if(position != -1) return;
	parameters.push_back(parameter);
	handlers.push_back(handler);
}
void OutputUpdateEvent::remove(OutputUpdateEventHandler handler){
	int position = handlerPosition(handler);
	if(position == -1) return;
	parameters.erase (parameters.begin()+position);
	handlers.erase (handlers.begin()+position);
}
void OutputUpdateEvent::dispatch(float value){
	for(int i=0; i<handlers.size(); i++){
		(parameters[i]->*(handlers[i]))(value);
	}
}
int OutputUpdateEvent::handlerPosition(OutputUpdateEventHandler handler){
	for(int i=0; i<handlers.size(); i++){
		if(handlers[i] == handler) return i;
	}
	return -1;
}