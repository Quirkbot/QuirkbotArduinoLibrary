#ifndef AnalogSensor_h_
#define AnalogSensor_h_

#include "Sensor.h"

class AnalogSensor :
public Sensor,
public Contains7Inputs<int, float, float, float, float, float, float>
{
	public:
	
	AnalogSensor():
	Contains7Inputs<int, float, float, float, float, float, float>
		(pin, begin, end, min, max, smoothing, interval){
		registerInput(pin);
	};

	void onInterval();

	Input<int> pin;

	protected:
	void onInternalInputChange(BaseInput &input);
};
typedef AnalogSensor LightSensor;

void AnalogSensor::onInternalInputChange(BaseInput &input){
	if(&input == &pin) pinMode(pin, INPUT);
};

void AnalogSensor::onInterval(){
	float reading = analogRead(pin);
	processReading(reading);
}

#endif
