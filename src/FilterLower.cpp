#include "FilterLower.h"
#include "Arduino.h"

FilterLower::FilterLower(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	value = 0;
}
FilterLower::~FilterLower(){}
void FilterLower::push(float number){
	a = b;
	b = c;
	c = d;
	d = number;

	value = min( min( min( a, b ), c ), d );
}
