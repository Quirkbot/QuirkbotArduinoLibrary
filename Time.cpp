#include "Time.h"

void Time::onInterval(){
	frames.set(Bot::frames);
	micros.set(Bot::micros);
	millis.set(Bot::millis);
	seconds.set(Bot::seconds);
}