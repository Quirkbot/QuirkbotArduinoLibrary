#ifndef Gate_h_
#define Gate_h_

#include "Bot.h"
#include "Node.h"
#include "HasTrigger.h"
#include "Input.h"
#include "Output.h"
#include "HasIn.h"
#include "HasOut.h"


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
	};
	
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

void Gate::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		if(isTriggerActive()){
			out.set(in.get());
		}
	}
};

#endif
