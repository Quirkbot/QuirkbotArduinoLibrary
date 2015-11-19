#include "Buzzer.h"

float Buzzer::MAX_FREQUENCY = 4978.0;
Buzzer::Buzzer(){

	registerInput(note);
	registerInput(place);

	note = NO_NOTE;
	place = NO_LOCATION;

	lastFrequency = 0;
}
Buzzer::~Buzzer(){}
float Buzzer::calculateTone(float frequency){
	return sqrt(frequency / MAX_FREQUENCY);
}
void Buzzer::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place){
		pinMode(place.get(), OUTPUT);
		process();
	}
	else if(&internalInput == &note){
		process();
	}
}
void Buzzer::process(){
	int frequency = (note.get() * note.get()) * MAX_FREQUENCY;
	if(lastFrequency == frequency) return;
	lastFrequency = frequency;
	if(frequency != 0) {
		::tone((uint8_t)place.get(), frequency);
	}
	else{
		::noTone((uint8_t)place.get());
	}
}
