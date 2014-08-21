#ifndef Gate_h_
#define Gate_h_

#include "Bot.h"
#include "Node.h"
#include "HasTrigger.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"


class Gate:
public Node,
public HasTrigger,
public InputOutputStream<float>
{
	public:
	
	Gate():
	HasTrigger
		(this),
	InputOutputStream<float>
		(source, value){
		registerInput(source);
		source = 0;	
		invert = false;
		closed = false;
	};

	Input<float> source;
	Input<bool> invert;

	Output<float> value;
	
	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	bool closed;

};

void Gate::onInternalInputChange(BaseInput &input){
	if(&input == &triggerInput){
		if(!invert){
			closed = !aboveTrigger();
		}
		else{
			closed = aboveTrigger();
		}
	}
	else if(&input == &source){
		if(!closed) value.set(source.get());
	}
};

#endif
