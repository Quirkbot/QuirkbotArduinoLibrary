#ifndef Bot_h_
#define Bot_h_

#include "Constants.h"
#include "Node.h"
#include "Updatable.h"

#include <vector>

class Node;
class Updatable;

class Bot {
	public:
	static void addNode(Node * node);
	static void removeNode(Node * node);
	static int nodePosition(Node * node);
	static void addUpdatable(Updatable * updatable);
	static void removeUpdatable(Updatable * updatable);
	static int updatablePosition(Updatable * updatable);


	static void update();

	static std::vector <Node *> nodes;
	static std::vector <Updatable *> updatables;
	static volatile unsigned long micros;
	static volatile float millis;
	static volatile float seconds;
	static volatile unsigned long frames;
};

#endif

