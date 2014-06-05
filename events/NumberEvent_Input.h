#ifndef NumberEvent_Input_h_
#define NumberEvent_Input_h_

#include <vector>

#include "Input.h";

class Input;

typedef void (Input::*NumberEventHandler_Input)(float);

class NumberEvent_Input {
	public:

	void add(Input* input, NumberEventHandler_Input handler);
	void remove(NumberEventHandler_Input handler);
	void dispatch(float value);
	int handlerPosition(NumberEventHandler_Input handler);
	
	private:
	// These lists must be in sync
	std::vector<Input*> inputs;
	std::vector<NumberEventHandler_Input> handlers;
};

#endif
