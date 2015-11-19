#include "LowerFilter.h"
#include "Arduino.h"

LowerFilter::LowerFilter(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	value = 0;
}
LowerFilter::~LowerFilter(){}
void LowerFilter::push(float number){
	a = b;
	b = c;
	c = d;
	d = number;

	value = min( min( min( a, b ), c ), d );
}
