#ifndef Output_h_
#define Output_h_

#include "events/NumberEvent_Input.h"

class NumberEvent_Input;
class Output {
	friend class Input;

	public:

	Output();
	~Output();

	operator float();
	float get();
	void set(float value);

	NumberEvent_Input* changed;
	
	protected:	


	private:

	float value;
		
};

#endif
