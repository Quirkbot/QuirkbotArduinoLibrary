#ifndef Bot_h_
#define Bot_h_

#include "Constants.h"
//#include "Node.h"
#include "Updatable.h"

#include "Vector.h"

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

	static Vector <Node *> nodes;
	static Vector <Updatable *> updatables;
	static volatile float micros;
	static volatile float millis;
	static volatile float seconds;
	static volatile float frames;
};

#endif

