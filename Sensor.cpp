#include "Sensor.h"

Sensor::Sensor(){
	registerInput(pin);
	registerInput(smoothing);
	registerInput(interval);

	smoothing = 0.5;
}

void Sensor::onPinChange(){
	pinMode(pin, INPUT);
}
void Sensor::onInternalInputChange(BaseInput &input){
	IntervalNode::onInternalInputChange(input);
	
	if(&input == &pin) onPinChange();
};

void Sensor::onInterval(){
	raw = analogRead(pin);
	float smoothingValue = smoothing;
	smooth = smooth * smoothingValue + raw * (1.0 - smoothingValue);

	value = smooth / 1024.0;
};
