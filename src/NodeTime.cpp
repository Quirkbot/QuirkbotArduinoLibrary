#include "NodeTime.h"

Time::Time():
HasInterval
	(this){
	interval = 0.001;
}
Time::~Time(){}
void Time::onInterval(){
	out.set(Bot::seconds());
}
