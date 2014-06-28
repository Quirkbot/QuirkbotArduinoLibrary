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
public OutputStream<float>
{
	public:
	
	Sensor():
	OutputStream<float>(value){
		registerInput(min);
		registerInput(max);
		registerInput(begin);
		registerInput(end);	
		registerInput(smoothing);
		
		min = 0.0;
		max = 1.0;
		begin = 0.0;
		end = 1.0;
		smoothing = 0.5;
		interval = 100;

		normalizingFactor = 1024.0;
	};

	Input<float> min;
	Input<float> max;
	Input<float> begin;
	Input<float> end;
	Input<float> smoothing;

	Output<float> raw;
	Output<float> value;

	protected:

	float normalizingFactor;

	void processReading(float reading){
		float smooth = smooth * smoothing + reading * (1.0 - smoothing);
		raw = smooth / normalizingFactor;
		value = mapFloat(raw, min, max, begin, end);
	}

};



#endif
