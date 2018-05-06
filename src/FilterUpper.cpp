#include "FilterUpper.h"
#include "Arduino.h"

FilterUpper::FilterUpper(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	value = 0;
}
FilterUpper::~FilterUpper(){}
void FilterUpper::push(float number){
	a = b;
	b = c;
	c = d;
	d = number;

	value = max( max( max( a, b ), c ), d );
}
