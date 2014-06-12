#include "Led.h"

Led::Led(){
	registerInput(pin);
	registerInput(brighteness);
}
void Led::onInternalInputChange(BaseInput &input){
	if(&input == &pin) onPinChange();
	else if(&input == &brighteness) onBrightenessChange();

};
void Led::onPinChange(){
	pinMode(pin, OUTPUT);
};
void Led::onBrightenessChange(){
	analogWrite(pin, pow(brighteness, 2.5) * 255.0);
};
