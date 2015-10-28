#ifndef Bot_h_
#define Bot_h_

#include <avr/wdt.h>

#include "Arduino.h"
#include "Keyboard.h"

#include "Board.h"
#include "Updatable.h"
#include "Node.h"

#include "Vector.h"

class Node;
class Updatable;

class Bot {
	public:
	Bot();
	~Bot();
	static void addNode(Node * node);
	static void removeNode(Node * node);
	static int nodePosition(Node * node);
	static void addUpdatable(Updatable * updatable);
	static void removeUpdatable(Updatable * updatable);
	static int updatablePosition(Updatable * updatable);

	static void beforeStart();
	static void afterStart();
	static void update();

	// Keyboard management
	static void pressKey(byte key);
	static void releaseKey(byte key);
	static void releaseAllKeys();

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


	static VectorNodesPointer nodes;
	static VectorUpdatablesPointer updatables;
	static bool forceSaveUuid;
	static byte uuid[QB_UUID_SIZE];
	static volatile unsigned long frames;
	static volatile unsigned long dtMicros;
	static volatile unsigned long micros;
	static volatile unsigned long millis;
	static volatile float seconds;
	static bool serialReportEnabled;
	static unsigned long reportMillisTick;
};

#endif
