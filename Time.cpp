#include "Time.h"

Time::Time():
HasInterval
	(this),
HasOut<float>
	(this){
	interval = 0.001;
}
void Time::onInterval(){
	out.set(Bot::seconds);
}