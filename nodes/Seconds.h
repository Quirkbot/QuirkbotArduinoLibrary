#ifndef Seconds_h_
#define Seconds_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Seconds : public BaseNode, public Updatable, public Outputable{
	public:
	void update();
};

#endif
