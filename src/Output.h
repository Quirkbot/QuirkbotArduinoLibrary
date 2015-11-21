#ifndef Output_h_
#define Output_h_

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

	private:

	float value;
};

#endif
