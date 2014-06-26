#include "IntervalNode.h"

IntervalNode::IntervalNode(){
	registerInput(interval);
	interval = 1;
}
void IntervalNode::update(){
	if((int)(Bot::millis) % (int)interval == 0) onInterval();
}
/*void IntervalNode::onInternalInputChange(BaseInput &input){
	if(&input == &interval) onIntervalChange();
};
void IntervalNode::onIntervalChange(){
	if(interval < 1) interval = 1;
};*/