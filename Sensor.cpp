#include "Sensor.h"

Sensor::Sensor(){
	registerInput(pin);
	registerInput(sensibility);
	registerInput(interval);

	sensibility = 0.5;
	interval = 20;
}
void Sensor::onInternalInputChange(BaseInput &input){
	IntervalNode::onInternalInputChange(input);
	
	if(&input == &sensibility)
		filterValue = 1.0 - sensibility;
};

void Sensor::onInterval(){
	raw = analogRead(pin);
	smooth = smooth * filterValue + raw * (1.0 - filterValue);

	value = smooth / 1024.0;
};
