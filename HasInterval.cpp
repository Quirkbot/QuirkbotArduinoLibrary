#include "HasInterval.h"

HasInterval::HasInterval(Node * node):
intervalNode(node){
	intervalNode->registerInput(interval);
	interval = 0.1;
	nextTick = Bot::millis + (unsigned long)(interval.get()*1000);
}
HasInterval::~HasInterval(){}
void HasInterval::update(){
	if(Bot::millis >= nextTick){
		nextTick = Bot::millis + (unsigned long)(interval.get()*1000);
		onInterval();
	}
}