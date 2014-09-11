#ifndef AnalogSensor_h_
#define AnalogSensor_h_

#include "Sensor.h"

class AnalogSensor :
public Sensor
{
	public:
	
	AnalogSensor(){
		registerInput(pin);
	};

	void onInterval();

	Input<int> pin;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

void AnalogSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pin) pinMode(pin.get(), INPUT);
};

void AnalogSensor::onInterval(){
	float reading = analogRead(pin.get());
	processReading(reading);
}

#endif
