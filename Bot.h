#ifndef Bot_h_
#define Bot_h_

#include "Arduino.h"
#include "Board.h"
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

	// Utils
	static float map(
		float x, 
		float inMin, float inMax, 
		float outMin, float outMax
	);
	static float minimum(float a, float b);
	static float maximum(float a, float b);
	static int locationToBackPin(int location);
	static int locationToFrontPin(int location);
	

	static Vector <Node *> nodes;
	static Vector <Updatable *> updatables;
	static volatile unsigned long frames;
	static volatile unsigned long dtMicros;
	static volatile unsigned long micros;
	static volatile unsigned long millis;
	static volatile float seconds;
};

#endif

