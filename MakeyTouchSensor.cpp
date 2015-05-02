#include "MakeyTouchSensor.h"

MakeyTouchSensor::MakeyTouchSensor():
HasOut
	(this){
	registerInput(place);
	
	place = -1;

	filter.alpha = 0.87;
}
MakeyTouchSensor::~MakeyTouchSensor(){}
void MakeyTouchSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) {
		int location = place.get();

		backPin = Bot::locationToBackPin(location);
		frontPin = Bot::locationToFrontPin(location);

		if(backPin == NO_LOCATION) return;

		// Internal pull up
		pinMode(PULL_UP_PIN, OUTPUT);
		digitalWrite(PULL_UP_PIN, HIGH);

		// Back pins as ground
		pinMode(backPin, OUTPUT);
		digitalWrite(backPin, LOW);

		switch(location){
			case H:
				tickA = 0;
				break;
			case LA:
				tickA = 1;
				break;
			case LL:
				tickA = 2;
				break;
			case RL:
				tickA = 3;
				break;
			case RA:
				tickA = 4;
				break;
		}

		tickB = tickA + 2;

		if(tickB > (QB_MAX_MAKEY_SENSORS-1) ){
			tickB -= QB_MAX_MAKEY_SENSORS;
		}
	}
};

void MakeyTouchSensor::update(){
	if(frontPin == NO_LOCATION) return;

	int tick = Bot::frames % QB_MAX_MAKEY_SENSORS;
	if( tick == tickB){
		pinMode(frontPin, INPUT);
	}
	else if( tick == tickA){
		int reading = digitalRead(frontPin);
		pinMode(frontPin, OUTPUT);
		digitalWrite(frontPin, LOW);

		filter.push(reading);

		if(Bot::seconds < 1.5) return;

		if(filter.get() < 0.3) out.set(1);
		else  out.set(0);
	}

}

void MakeyTouchSensor::serialReport(){
	Serial.write((byte)(out.get() * 249));
}