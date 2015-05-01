#include "Randomizer.h"

Randomizer::Randomizer():
HasInterval
	(this),
HasOut
	(this){

	interval = 0.033;
}

void Randomizer::onInterval(){
	out.set((float)random(1000) * 0.001);
}