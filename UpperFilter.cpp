#include "UpperFilter.h"
#include "Arduino.h"

UpperFilter::UpperFilter(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	value = 0;
}
void UpperFilter::push(float number){
	a = b;
	b = c;
	c = d;
	d = number;

	value = max( max( max( a, b ), c ), d );
}