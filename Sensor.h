#ifndef Sensor_h_
#define Sensor_h_

#include "Arduino.h"

#include "Bot.h"
#include "IntervalNode.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "ContainsOutputs.h"
#include "Streams.h"

class Sensor :
public IntervalNode,
public OutputStream<float>,
public Contains3Inputs<float,int,float>,
public Contains1Output<float>
{
	public:
	
	Sensor():
	OutputStream<float>(value),
	Contains3Inputs<float,int,float>(interval, pin, smoothing),
	Contains1Output<float>(value){
		registerInput(pin);
		registerInput(smoothing);
		smoothing = 0.5;
		interval = 100;
	};

	void onInterval();

	Input<int> pin;
	Input<float> smoothing;

	Output<float> value;

	protected:
	void onInternalInputChange(BaseInput &input);

	float raw;
	float smooth;
};

void Sensor::onInternalInputChange(BaseInput &input){
	if(&input == &pin) pinMode(pin, INPUT);
};

void Sensor::onInterval(){
	raw = analogRead(pin);
	float smoothingValue = smoothing;
	smooth = smooth * smoothingValue + raw * (1.0 - smoothingValue);

	value = smooth / 1024.0;
};


#endif
