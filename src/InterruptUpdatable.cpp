#include "InterruptUpdatable.h"

InterruptUpdatable::InterruptUpdatable(){
	Bot::addInterruptUpdatable(this);
}
InterruptUpdatable::~InterruptUpdatable(){
	Bot::removeInterruptUpdatable(this);
}
