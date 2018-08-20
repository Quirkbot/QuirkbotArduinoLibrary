#include "InterruptUpdatable.h"

InterruptUpdatable::InterruptUpdatable(){
	Bot::interruptUpdatables.add(this);
}
InterruptUpdatable::~InterruptUpdatable(){
	Bot::interruptUpdatables.remove(this);
}
