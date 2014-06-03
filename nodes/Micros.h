#ifndef Micros_h_
#define Micros_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Micros : public BaseNode, public Updatable, public Outputable{
	public:
	void update();
};

#endif
