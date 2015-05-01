#ifndef OutputFloat_h_
#define OutputFloat_h_

#include "Event.h"
#include "InputFloat.h"

class Event;

class OutputFloat {
	public:

	OutputFloat();
	~OutputFloat();


	/**
	 * Handle for input connections.
	 **/
	void connect(InputFloat &input);

	/**
	 * Getter and setter.
	 **/
	void set(float value);
	float get();

	Event event;

	private:

	float value;
};

#endif
