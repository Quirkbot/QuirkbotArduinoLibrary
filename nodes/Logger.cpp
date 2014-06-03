#include "Logger.h"

Logger::Logger(){
	init(Serial);
}
Logger::Logger(Stream& stream){
	init(stream);
}
void Logger::init(Stream &stream){
	this->streamPtr = &stream;
	input.setParent(this);
	interval.setParent(this);
	lastPrintMillis = Bot::millis;
}
void Logger::onParameterUpdated(Parameter& parameter){
	if(Bot::millis - lastPrintMillis < interval.getValue())
		return;
	
	lastPrintMillis = Bot::millis;
	streamPtr->println(input.getValue());
};