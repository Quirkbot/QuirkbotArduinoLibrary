#ifndef Randomizer_h_
#define Randomizer_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"
#include "ContainsInputs.h"

class Randomizer :
public Node,
public HasInterval,
public Contains2Inputs<float, float>,
public OutputStream<float>
{
	public:

	Randomizer():
	HasInterval
		(this),
	Contains2Inputs<float, float>
		(min, max),
	OutputStream<float>
		(value){
		registerInput(min);
		registerInput(max);

		interval = 0.033;

		min = 0.0;
		max = 1.0;
	};

	void onInterval();

	Input<float> min;
	Input<float> max;

	Output<float> value;
};

void Randomizer::onInterval(){
	value = mapFloat((float)(random(1000)) * 0.001, 0.0, 1.0, min, max);
}

#endif
