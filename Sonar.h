#ifndef Sonar_h_
#define Sonar_h_

#include "Sensor.h"

class Sonar :
public Sensor
{
	public:
	
	Sonar(){
		registerInput(pin);

		centimetersConverter = 27.0;
		inchesConverter = 146.0;
		normalizingFactor = 5000.0;
	};

	void onInterval();

	Input<int> pin;

	Output<float> micros;
	Output<float> centimeters;
	Output<float> inches;

	float centimetersConverter;
	float inchesConverter;
	
	protected:
	void onInternalInputChange(BaseInput &input);
};

void Sonar::onInternalInputChange(BaseInput &input){
	if(&input == &interval){
		if(interval < 0.05) interval = 0.05;
	}
};
void Sonar::onInterval(){
	if(pin == -1) return;


	pinMode(pin, OUTPUT);

	digitalWrite(pin, LOW);
	delayMicroseconds(2);
	digitalWrite(pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(pin, LOW);

	pinMode(pin, INPUT);

	float reading = pulseIn(pin, HIGH, 5000);

	if(reading == 0) reading = 5000;

	processReading(reading);

	micros = value;
	centimeters = value / centimetersConverter;
	inches = value / inchesConverter;
};


#endif
