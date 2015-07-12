#include "MedianFilter.h"

MedianFilter::MedianFilter(){
	a = 0;
	b = 0;
	c = 0;
	value = 0;
}
void MedianFilter::push(float number){
	a = b;
	b = c;
	c = number;

	if (c < b) {
		if (c < a) {
			if (b < a) value = b;
			else value = a;
		}
		else value = c;
	}
	else {
		if (c < a) value = c;
		else {
			if (b < a) value = a;
			else value = b;
		}
	}
}