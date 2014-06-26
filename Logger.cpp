#include "Logger.h"

Logger::Logger():
InputStream<float>(base),
Contains5Inputs<float, char*, float, float, float>
(base, label, throttle, showLabel, showTimestamp){
	init(Serial);
}
void Logger::init(Stream &stream){
	registerInput(base);
	registerInput(label);
	registerInput(throttle);
	registerInput(showLabel);
	registerInput(showTimestamp);

	label = "Print";
	throttle = 100;
	showLabel = false;
	showTimestamp = false;

	streamPtr = &stream;
	lastPrintMillis = Bot::millis;
}
void Logger::onInternalInputChange(BaseInput &input){
	if(&input != &base) return;
	if(Bot::millis - lastPrintMillis < throttle) return;

	lastPrintMillis = Bot::millis;
	if(showLabel){
		streamPtr->print(label);
		streamPtr->print("\t");
		streamPtr->print("|");
		streamPtr->print("\t");

	}
	if(showTimestamp){
		streamPtr->print(Bot::millis,0);
		streamPtr->print("ms");
		streamPtr->print("\t");
		streamPtr->print("|");
		streamPtr->print("\t");
	}

	streamPtr->println(base, 3);
};