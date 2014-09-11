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
public HasOut<float>
{
	public:
	
	Sensor():
	HasInterval
		(this),
	HasOut<float>
		(this){
		registerInput(smoothing);
		smooth = 0;
		normalizingFactor = 1024.0;

		smoothing = 0.5;
		interval = 0.1;	
	};

	Input<float> smoothing;

	protected:

	float normalizingFactor;
	float smooth;

	void processReading(float reading){
		smooth = smooth * smoothing.get() + reading * (1.0 - smoothing.get());
		out.set( smooth / normalizingFactor );
	}

};



#endif
