#ifndef Sequence_h_
#define Sequence_h_

#include "Bot.h"
#include "IntervalNode.h"
#include "CollectionNode.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"


class Sequence:
public IntervalNode,
public CollectionNode<float>,
public InputOutputStream<float>
{
	public:
	
	Sequence():
	InputOutputStream<float>
		(trigger, value){
		IntervalNode::registerInput(trigger);
		IntervalNode::registerInput(duration);
		selected = NULL;

		interval = 33;
		duration = 1000;
		trigger = 0;
		
	};

	void onInterval();

	Input<float> trigger;
	Input<float> duration;

	Output<float> value;
	
	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	Input<float> * selected;
	bool running;
	float startMillis;

};
void Sequence::onInterval(){
	if(!running) return;
	float position = (Bot::millis - startMillis) / duration;
	if(position > 1){
		position = 1;
		running = false;
	}
	int i = floor(position * items.size());
	if( i == items.size()) i = items.size() - 1;
	if(items[i] != selected){
		selected = items[i];
		value.set(selected->get());
	}
}

void Sequence::onInternalInputChange(BaseInput &input){
	if(&input == &trigger){
		if(!running && trigger > 0.5){
			startMillis = Bot::millis;
			running = true;
			onInterval(); // start immediatelly
		}
	}
};

#endif
