#ifndef Randomizer_h_
#define Randomizer_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"

class Randomizer :
public Node,
public HasInterval,
public OutputStream<float>
{
	public:

	Randomizer():
	HasInterval
		(this),
	OutputStream<float>
		(value){

		interval = 0.033;
	};

	void onInterval();

	Output<float> value;
};

void Randomizer::onInterval(){
	value = (float)random(1000) * 0.001;
}

#endif
