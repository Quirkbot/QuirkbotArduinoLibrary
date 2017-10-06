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

// Serial Report constants
#define REPORT_INTERVAL_MILLIS 100
#define REPORT_UUID_INTERVAL_TICKS 10
#define REPORT_START_DELIMITER 250
#define REPORT_END_DELIMITER 255
#define REPORT_UUID_DELIMITER 251
#define REPORT_NUMBER_OF_NODES_DELIMITER 252
#define REPORT_NODE_CONTENT_DELIMITER 253

// Bootloader support
#define BOOTLOADER_ID_SIGNATURE_START		((FLASHEND + 1UL) - 2)
#define BOOTLOADER_ID_SIGNATURE_SIZE		2
#define BOOTLOADER_VERSION_SIGNATURE_START 	((FLASHEND + 1UL) - 4)
#define BOOTLOADER_VERSION_SIGNATURE_SIZE	2


// Enums
namespace BotMIDICommands{
	enum Enum {
		Sync = 0xa,
		EnterBootloader = 0xb,
		Data = 0xd,
		ReadUUID = 0xf
	};
}

namespace BotSerialCommands{
	enum Enum {
		EnterBootloader = 0xb
	};
}

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
	static void afterStart();
	static void update();
	static volatile void interruptUpdate();

	// USB interfaces
	static void serialTask();
	static void midiTask();
	static void sendMidiData(uint8_t command, uint8_t byte1, uint8_t byte2);
	static void dataToMidi(uint8_t command, uint8_t byte1, uint8_t byte2, midiEventPacket_t * packet);
	static void midiToData(midiEventPacket_t *packet, uint8_t *command, uint8_t *byte1, uint8_t *byte2);

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
	static float constrain(float x, float min, float max);
	static float seconds();
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
	static bool serialReportEnabled;
	static unsigned long reportMillisTick;

};

#endif
