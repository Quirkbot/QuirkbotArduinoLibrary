#ifndef Sensor_h_
#define Sensor_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Updatable.h"
#include "Input.h"
#include "Output.h"




class Sensor : public Node, public Updatable{
	public:
	
	Sensor();

	void update();

	Input<int> pin;
	Input<float> sensibility;
	Input<float> frequency;

	Output<float> value;

	protected:
	void onInternalInputChange(BaseInput &input);

	float raw;
	float smooth;
	float filterValue;
	int frequencyFrames;
};

#endif
