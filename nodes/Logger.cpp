#include "Logger.h"

Logger::Logger(){
	init(Serial);
}
Logger::Logger(Stream& stream){
	init(stream);
}
void Logger::init(Stream &stream){
	registerInput(source);
	registerInput(interval);

	interval = 100;

	streamPtr = &stream;
	lastPrintMillis = Bot::millis;
}
void Logger::onInternalInputChange(BaseInput &input){
	if(&input == &source) onSourceChange();
};
void Logger::onSourceChange(){
	if(Bot::millis - lastPrintMillis < interval)
		return;
	
	lastPrintMillis = Bot::millis;
	streamPtr->println(source);
};
