#include "NodeRandomizer.h"

Randomizer::Randomizer():
HasInterval
	(this){
	registerInput(min);
	registerInput(max);

	min = 0;
	max = 1;
	interval = 0.5;
}
Randomizer::~Randomizer(){}
void Randomizer::onInterval(){
	out.set(Bot::map((float)random(1000), 0, 1000, min.get(), max.get()));
}
