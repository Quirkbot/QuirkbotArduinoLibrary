#ifndef OutputUpdateEvent_h_
#define OutputUpdateEvent_h_

#include <vector>

#include "Parameter.h";

class Parameter;

typedef void (Parameter::*OutputUpdateEventHandler)(float);

class OutputUpdateEvent {
	friend class Parameter;
	
	public:

	void add(Parameter* parameter, OutputUpdateEventHandler handler);
	void remove(OutputUpdateEventHandler handler);
	void dispatch(float value);
	int handlerPosition(OutputUpdateEventHandler handler);
	
	private:
	// These lists must be in sync
	std::vector<Parameter*> parameters;
	std::vector<OutputUpdateEventHandler> handlers;
};

#endif
