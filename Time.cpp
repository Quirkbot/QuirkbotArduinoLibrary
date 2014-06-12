#include "Time.h"

Time::Time(){
	registerInput(interval);
	interval = 1;
}
void Time::update(){
	if((int)(Bot::millis) % (int)interval != 0) return;

	frames.set(Bot::frames);
	micros.set(Bot::micros);
	millis.set(Bot::millis);
	seconds.set(Bot::seconds);
}
void Time::onInternalInputChange(BaseInput &input){
	if(&input == &interval) onIntervalChange();
};
void Time::onIntervalChange(){
	if(interval < 1) interval = 1;
};