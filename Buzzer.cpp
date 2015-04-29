#include "Buzzer.h"

float Buzzer::MAX_FREQUENCY = 4978.0;
Buzzer::Buzzer():
HasIn<float>
	(this){

	registerInput(place);

	lastFrequency = 0;
}
float Buzzer::calculateTone(float frequency){
	return sqrt(frequency / MAX_FREQUENCY);
}
void Buzzer::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		pinMode(place.get(), OUTPUT);
		process();
	}
	else if(&internalInput == &in){
		process();
	}
}
void Buzzer::process(){
	int frequency = (in.get() * in.get()) * MAX_FREQUENCY;
	if(lastFrequency == frequency) return;
	lastFrequency = frequency;
	if(frequency != 0) {
		::tone((uint8_t)place.get(), frequency);
	}
	else{
		::noTone((uint8_t)place.get());
	}
}