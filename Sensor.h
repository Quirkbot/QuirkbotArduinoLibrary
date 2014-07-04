#ifndef Sensor_h_
#define Sensor_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"

class Sensor :
public Node,
public HasInterval,
public OutputStream<float>
{
	public:
	
	Sensor():
	HasInterval
		(this),
	OutputStream<float>
		(value){
		registerInput(smoothing);
		smooth = 0;
		normalizingFactor = 1024.0;

		smoothing = 0.5;
		interval = 0.1;	
	};

	Input<float> smoothing;

	Output<float> value;

	protected:

	float normalizingFactor;
	float smooth;

	void processReading(float reading){
		smooth = smooth * smoothing + reading * (1.0 - smoothing);
		value = smooth / normalizingFactor;
	}

};



#endif
