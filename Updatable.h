#ifndef Updatable_h_
#define Updatable_h_

#include "Bot.h"

class Bot;

class Updatable{
	friend class Bot;

	public:

	Updatable();
	~Updatable();

	protected:
		
	virtual void update(){};
};

#endif
