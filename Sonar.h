#ifndef Sonar_h_
#define Sonar_h_

#include "CommonNodeIncludes.h"

class Sonar :
public Node,
public HasInterval,
public HasOut<float>
{
	public:
	
	Sonar():
	HasInterval
		(this),
	HasOut<float>
		(this){
		registerInput(pin);

		pin = -1;
	};

	void onInterval();

	Input<int> pin;

	protected:

	MedianFilter medianFilter;
};

void Sonar::onInterval(){
	if(pin.get() == -1) return;


	pinMode(pin.get(), OUTPUT);

	digitalWrite(pin.get(), LOW);
	delayMicroseconds(2);
	digitalWrite(pin.get(), HIGH);
	delayMicroseconds(5);
	digitalWrite(pin.get(), LOW);

	pinMode(pin.get(), INPUT);

	float reading = pulseIn(pin.get(), HIGH, 5000);
	if(reading == 0) reading = 5000;
	medianFilter.push( reading );
	
	out.set(medianFilter.get() / 5000.0);	
}

#endif