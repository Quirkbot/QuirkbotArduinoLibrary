#include "Sensor.h"

Sensor::Sensor(){
	registerInput(pin);
	registerInput(sensibility);
	registerInput(frequency);

	sensibility = 0.5;
	frequency = 100;
}
void Sensor::onInternalInputChange(BaseInput &input){
	if(&input == &frequency)
		frequencyFrames = BOT_MILLIS_TO_FRAMES(frequency);
	else if(&input == &sensibility)
		filterValue = 1.0 - sensibility;
};

void Sensor::update(){
	if(Bot::frames % frequencyFrames != 0) return;
	
	raw = analogRead(pin);
	smooth = smooth * filterValue + raw * (1.0 - filterValue);

	value = smooth;
};
