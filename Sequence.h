#ifndef Sequence_h_
#define Sequence_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "HasInputCollection.h"
#include "HasTrigger.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"


class Sequence:
public Node,
public HasInterval,
public HasInputCollection<float>,
public HasTrigger,
public InputOutputStream<float>
{
	public:
	
	Sequence():
	HasInterval
		(this),
	HasInputCollection<float>
		(this),
	HasTrigger
		(this),
	InputOutputStream<float>
		(trigger, value){
		registerInput(duration);
		selected = NULL;

		interval = 0.033;
		duration = 1.0;
		
	};

	void onInterval();

	Input<float> duration;

	Output<float> value;
	
	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	Input<float> * selected;
	bool running;
	float startTime;

};
void Sequence::onInterval(){
	if(!running) return;
	float position = (Bot::seconds - startTime) / duration;
	if(position > 1){
		position = 1;
		running = false;
	}
	int i = floor(position * inputCollection.size());
	if( i == inputCollection.size()) i = inputCollection.size() - 1;
	if(inputCollection[i] != selected){
		selected = inputCollection[i];
		value.set(selected->get());
	}
}

void Sequence::onInternalInputChange(BaseInput &input){
	if(&input == &trigger){
		if(!running && aboveTrigger()){
			startTime = Bot::seconds;
			running = true;
			onInterval(); // start immediatelly
		}
	}
};

#endif
