#ifndef Output_h_
#define Output_h_

#include "Event.h"
#include "Input.h"

class Output {
	public:

	Output();
	~Output();


	/**
	 * Handle for input connections.
	 **/
	void connect(Input &input);

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
