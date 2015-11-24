#ifndef Event_h_
#define Event_h_

#include "Vector.h"

class Input;

class Event {
	public:

	Event();
	~Event();

	typedef void (Input::*TypedInputHandler)(float value);

	void add(Input* input, TypedInputHandler handler);
	void remove(TypedInputHandler handler);
	void dispatch(float &value);

	private:
	int position(TypedInputHandler handler);

	VectorTypedInputHandler typedInputHandlers;
	VectorInputsPointer typedInputs;

};

#endif
