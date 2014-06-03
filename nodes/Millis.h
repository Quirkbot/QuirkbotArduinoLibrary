#ifndef Millis_h_
#define Millis_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Millis : public BaseNode, public Updatable, public Outputable{
	public:
	void update();
};

#endif
