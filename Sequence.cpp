#include "Sequence.h"

Sequence::Sequence():
HasInterval
	(this),
HasInputCollection<float>
	(this),
HasTrigger
	(this),
HasOut<float>
	(this){
	registerInput(duration);
	selected = NULL;

	interval = 0.033;
	duration = 1.0;
}
void Sequence::onInterval(){
	if(!running) return;
	float position = (Bot::seconds - startTime) / duration.get();
	if(position > 1){
		position = 1;
		running = false;
	}
	int i = floor(position * items.size());
	if( i == items.size()) i = items.size() - 1;
	if(items[i] != selected){
		selected = items[i];
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
}