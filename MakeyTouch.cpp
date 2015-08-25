#include "MakeyTouch.h"

MakeyTouch::MakeyTouch():
HasOut
	(this){
	registerInput(place);
	registerInput(min);
	registerInput(max);

	place = NO_LOCATION;
	min = 0;
	max = 1;

	filter.alpha = 0.87;
}
MakeyTouch::~MakeyTouch(){}
void MakeyTouch::onInternalInputChange(BaseInput &internalInput){
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

void MakeyTouch::update(){
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

		if(filter.get() < 0.3) out.set(max.get());
		else  out.set(min.get());
	}

}

void MakeyTouch::serialReport(){
	byte b = (byte)(out.get() * 249);
	Serial.write(b);
}