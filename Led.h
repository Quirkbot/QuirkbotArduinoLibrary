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
	Input<bool> on;
	Input<bool> off;

	protected:

	void onPinChange();
	void onBrightenessChange();
	void onOn();
	void onOff();

	void onInternalInputChange(BaseInput &input);
};

#endif
