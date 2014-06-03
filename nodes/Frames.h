#ifndef Frames_h_
#define Frames_h_

#include "Bot.h"
#include "BaseNode.h"
#include "Outputable.h"

class Frames : public BaseNode, public Updatable, public Outputable{
	public:
	void update();
};

#endif
