#ifndef InterruptUpdatable_h_
#define InterruptUpdatable_h_

#include "Bot.h"

class Bot;

class InterruptUpdatable{
	friend class Bot;

	public:

	InterruptUpdatable();
	~InterruptUpdatable();

	protected:

	virtual void interruptUpdate(){};
};

#endif
