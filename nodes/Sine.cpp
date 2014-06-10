#include "Sine.h"

Sine::Sine(){
	registerInput(source);
}
void Sine::onInternalInputChange(BaseInput &input){
	if(&input == &source) onSourceChange();
};
void Sine::onSourceChange(){
	result = sin(source);
};
