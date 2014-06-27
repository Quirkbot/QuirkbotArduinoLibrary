#include "Logger.h"

Logger::Logger():
InputStream<float>(a),
Contains6Inputs<float, float, float, float, float, float>
(a, b, c, d, e, throttle){
	registerInput(a);
	registerInput(b);
	registerInput(c);
	registerInput(d);
	registerInput(e);
	registerInput(throttle);

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	throttle = 100;

	lastPrintMillis = Bot::millis;
}
void Logger::onInternalInputChange(BaseInput &input){
	if(&input == &throttle) return;
	if(Bot::millis - lastPrintMillis < throttle) return;

	lastPrintMillis = Bot::millis;
	if(a) {
		Serial.print(a, 4);	
	}
	if(b) {
		Serial.print("\t|\t");
		Serial.print(b, 4);
	}
	if(c) {
		Serial.print("\t|\t");
		Serial.print(c, 4);
	}
	if(d) {
		Serial.print("\t|\t");
		Serial.print(d, 4);
	}
	if(e) {
		Serial.print("\t|\t");
		Serial.print(e, 4);
	}
	Serial.print("\n");
};