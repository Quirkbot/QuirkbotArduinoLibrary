#ifndef DigitalSensor_h_
#define DigitalSensor_h_

#include "Sensor.h"

class DigitalSensor :
public Sensor
{
	public:
	
	DigitalSensor(){
		registerInput(pin);
		normalizingFactor = 1.0;
		interval = 0.005;
		smoothing = 0.97;
		processReading(0);
	};

	void onInterval();

	Input<int> pin;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

void DigitalSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin) pinMode(pin.get(), INPUT);
};

void DigitalSensor::onInterval(){
	float reading = digitalRead(pin.get());
	processReading(reading);
}

#endif
