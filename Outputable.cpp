#include "Outputable.h"

Outputable::Outputable(){
	outputUpdated = new OutputUpdateEvent();
	output = 0;
}
Outputable::~Outputable(){
	delete outputUpdated;
}
float Outputable::getOutput(){
	return output;
}
void Outputable::updateOutput(float output){
	if(this->output == output) return;
	this->output = output;
	outputUpdated->dispatch(output);
	updated.dispatch(output);
}