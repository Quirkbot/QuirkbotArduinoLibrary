#ifndef Led_h_
#define Led_h_

#include "math.h"

#include "Node.h"
#include "Input.h"

#include "Arduino.h"


class Led : public Node{
	public:
	
	Led();

	Input<unsigned int> pin;
	Input<float> brighteness;

	protected:

	void onInternalInputChange(BaseInput &input);
	
	void onPinChange();
	void onBrightenessChange();
};

#endif
