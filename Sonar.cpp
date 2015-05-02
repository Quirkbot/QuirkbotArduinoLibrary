#include "Sonar.h"

Sonar::Sonar():
HasInterval
	(this),
HasOut
	(this){
	registerInput(place);

	place = BP4;
}
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
	
	out.set(medianFilter.get() / 5000.0);
}