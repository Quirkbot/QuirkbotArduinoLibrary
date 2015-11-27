#include "Sequence.h"

Sequence::Sequence():
HasInterval
	(this),
HasTrigger
	(this),
HasOut
	(this){
	registerInput(duration);
	registerInputCollection(items);
	selected = NULL;

	interval = 0.033;
	duration = 1.0;
}
Sequence::~Sequence(){}
void Sequence::onInterval(){
	if(!running) return;
	float position = (Bot::seconds - startTime) / duration.get();
	if(position > 1){
		position = 1;
		running = false;
	}
	int i = floor(position * items.collection.size());
	if( i == items.collection.size()) i = items.collection.size() - 1;
	if(items.collection[i] != selected){
		selected = items.collection[i];
		out.set(selected->get());
	}
}
void Sequence::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &trigger){
		if(!running && isTriggerActive()){
			startTime = Bot::seconds;
			running = true;
			onInterval(); // start immediatelly
		}
	}
	else if(&internalInput == selected){
		out.set(selected->get());
	}
}
