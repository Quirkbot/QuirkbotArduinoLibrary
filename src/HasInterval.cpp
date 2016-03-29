#include "HasInterval.h"

HasInterval::HasInterval(Node * node):
intervalNode(node){
	intervalNode->registerInput(interval);
	interval = 0.1;
	nextTick = ::millis() + (unsigned long)(interval.get()*1000);
}
HasInterval::~HasInterval(){}
void HasInterval::update(){
	if(::millis() >= nextTick){
		nextTick += (unsigned long)(interval.get()*1000);
		onInterval();
	}
}
