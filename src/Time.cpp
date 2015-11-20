#include "Time.h"

Time::Time():
HasInterval
	(this),
HasOut
	(this){
	interval = 0.001;
}
Time::~Time(){}
void Time::onInterval(){
	out.set(Bot::seconds);
}