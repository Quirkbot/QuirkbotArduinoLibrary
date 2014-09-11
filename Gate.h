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
public HasIn<float>,
public HasOut<float>
{
	public:
	
	Gate():
	HasTrigger
		(this),
	HasIn<float>
		(this),
	HasOut<float>
		(this){

		closed = false;
	};
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	bool closed;

};

void Gate::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &triggerInput){
		closed = !aboveTrigger();
	}
	else if(&internalInput == &in){
		if(!closed) out.set(in.get());
	}
};

#endif
