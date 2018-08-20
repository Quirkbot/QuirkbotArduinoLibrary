#ifndef Event_h_
#define Event_h_

#include "Vector.h"

class Input;
typedef void (Input::*InputHandler)(float value);

class Event {
	public:

	Event();
	~Event();

	void add(Input* input, InputHandler handler);
	void remove(Input* input, InputHandler handler);
	void dispatch(float &value);

	private:
	int position(Input* input, InputHandler handler);

	Vector<InputHandler> handlers;
	Vector<Input*> inputs;

};

#endif
