#include "Led.h"

Led::Led(){
	registerInput(pin);
	registerInput(brighteness);
	registerInput(on);
	registerInput(off);
}
void Led::onPinChange(){
	pinMode(pin, OUTPUT);
};
void Led::onBrightenessChange(){
	analogWrite(pin, pow(brighteness, 2.5) * 255.0);
};
void Led::onOn(){
	brighteness = 1;
};
void Led::onOff(){
	brighteness = 0;
};
void Led::onInternalInputChange(BaseInput &input){
	if(&input == &pin) onPinChange();
	else if(&input == &brighteness) onBrightenessChange();
	else if(&input == &on) onOn();
	else if(&input == &off) onOff();
};