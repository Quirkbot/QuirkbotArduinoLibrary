#ifndef Sensor_h_
#define Sensor_h_

#include "Arduino.h"

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"



class Sensor : public IntervalNode{
	public:
	
	Sensor();

	void onInterval();

	Input<int> pin;
	Input<float> smoothing;

	Output<float> value;

	protected:
	void onInternalInputChange(BaseInput &input);
	void onPinChange();

	float raw;
	float smooth;
};

#endif
