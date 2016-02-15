#ifndef Bot_h_
#define Bot_h_

#include <avr/wdt.h>

#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "MIDIUSB.h"

#include "Updatable.h"
#include "InterruptUpdatable.h"
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
	static void addInterruptUpdatable(InterruptUpdatable * interruptUpdatable);
	static void removeInterruptUpdatable(InterruptUpdatable * interruptUpdatable);
	static int interruptUpdatablePosition(InterruptUpdatable * interruptUpdatable);

	static void start();
	static void update();
	static volatile void interruptUpdate();

	// USB interfaces
	static void serialTask();
	static void midiTask();

	// Keyboard management
	static void pressKey(byte key);
	static void releaseKey(byte key);
	static void releaseAllKeys();

	// Bootloader support
	static uint16_t readFlashWord(uint16_t address);
	static uint16_t getBootloaderId();
	static uint16_t getBootloaderVersion();
	static void enterBootloader();

	// Utils
	static float map(
		float x,
		float inMin, float inMax,
		float outMin, float outMax
	);
	static float minimum(float a, float b);
	static float maximum(float a, float b);
	static int locationToAnalogPin(int location);
	static int locationToBackPin(int location);
	static int locationToFrontPin(int location);

	static const unsigned int INTERUPT_COUNT_OVERFLOW;

	static VectorNodesPointer nodes;
	static VectorUpdatablesPointer updatables;
	static VectorInterruptUpdatablesPointer interruptUpdatables;
	static bool forceSaveUuid;
	static byte uuid[QB_UUID_SIZE];
	static volatile unsigned int interruptCount;
	static unsigned long frames;
	static unsigned long dtMicros;
	static unsigned long micros;
	static unsigned long millis;
	static float seconds;
	static bool serialReportEnabled;
	static unsigned long reportMillisTick;

};

#endif
