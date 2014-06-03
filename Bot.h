#ifndef Bot_h_
#define Bot_h_

#include "Constants.h"
#include "BaseNode.h"
#include "Updatable.h"

#include <vector>

class BaseNode;
class Updatable;

class Bot {
	public:
	static void addNode(BaseNode * node);
	static void removeNode(BaseNode * node);
	static int nodePosition(BaseNode * node);
	static void addUpdatable(Updatable * updatable);
	static void removeUpdatable(Updatable * updatable);
	static int updatablePosition(Updatable * updatable);


	static void update();

	static std::vector <BaseNode *> nodes;
	static std::vector <Updatable *> updatables;
	static volatile unsigned long micros;
	static volatile float millis;
	static volatile float seconds;
	static volatile unsigned long frames;
};

#endif

