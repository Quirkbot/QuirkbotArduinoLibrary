#ifndef Range_h_
#define Range_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"

class Range :
public Node,
public InputOutputStream<float>
{
	public:
	
	Range():
	InputOutputStream<float>
		(source, value){
		registerInput(min);
		registerInput(source);
		registerInput(max);
		
		source = 0.0;
		min = 0.0;
		max = 1.0;
	};

	Input<float> source;
	
	Input<float> min;
	Input<float> max;

	Output<float> value;

	protected:

	void onInternalInputChange(BaseInput &input);
};

void Range::onInternalInputChange(BaseInput &input){
	if(&input == &source){
		value = mapFloat(source, min, max, 0.0, 1.0);
	}
};

#endif
