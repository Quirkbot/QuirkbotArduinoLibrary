#include "NodeSonar.h"

Sonar::Sonar():
HasInterval
	(this){
	registerInput(meters);
	registerInput(place);
	registerInput(min);
	registerInput(max);

	meters = 4;
	place = NO_LOCATION;
	min = 0;
	max = 1;
}
Sonar::~Sonar(){}
void Sonar::onInterval(){
	if(place.get() == -1) return;


	pinMode(place.get(), OUTPUT);

	digitalWrite(place.get(), LOW);
	delayMicroseconds(2);
	digitalWrite(place.get(), HIGH);
	delayMicroseconds(5);
	digitalWrite(place.get(), LOW);

	pinMode(place.get(), INPUT);

	float reading = pulseIn(place.get(), HIGH, 5000);
	if(reading == 0) reading = 5000;
	medianFilter.push( reading );

	float centimeters = medianFilter.get() / 29 / 2;
	out.set(Bot::map(centimeters, 0, meters.get()*100, min.get(), max.get()));
}
