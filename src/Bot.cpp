#include <avr/eeprom.h>
#include "Bot.h"

#define REPORT_INTERVAL_MILLIS 100
#define REPORT_UUID_INTERVAL_TICKS 10
#define REPORT_START_DELIMITER 250
#define REPORT_END_DELIMITER 255
#define REPORT_UUID_DELIMITER 251
#define REPORT_NUMBER_OF_NODES_DELIMITER 252
#define REPORT_NODE_CONTENT_DELIMITER 253

const unsigned int Bot::INTERUPT_COUNT_OVERFLOW = 100;

VectorNodesPointer Bot::nodes = VectorNodesPointer();
VectorUpdatablesPointer Bot::updatables = VectorUpdatablesPointer();
VectorInterruptUpdatablesPointer Bot::interruptUpdatables = VectorInterruptUpdatablesPointer();
bool Bot::forceSaveUuid = false;
byte Bot::uuid[QB_UUID_SIZE] = {0x00};
volatile unsigned int Bot::interruptCount = 0;
unsigned long Bot::frames = 0;
unsigned long Bot::dtMicros = 0;
unsigned long Bot::micros = 0;
unsigned long Bot::millis = 0;
float Bot::seconds = 0;
unsigned long Bot::reportMillisTick = 0;
bool Bot::serialReportEnabled = true;

Bot::Bot(){}
Bot::~Bot(){}
void Bot::beforeStart(){
<<<<<<< HEAD:Bot.cpp

	// Start serial
	Serial.begin(115200);

	// Start Keyboard
	Keyboard.begin();

	// Force mouth to turn off (only used if you have to use  'LillyPad USB' as the board)
	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);
=======
	// Start Serial
	Serial.begin(115200);

	// Start HID
	Keyboard.begin();
	Mouse.begin();
>>>>>>> develop:src/Bot.cpp

	// Startup animation
	pinMode(LE, OUTPUT);
	pinMode(RE, OUTPUT);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);
	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);
	for (int i = 0; i < 2; i++) {
		PORTB |= (1<<0);
		delay(50);
		PORTB &= ~(1<<0);
		digitalWrite(RE, HIGH);
		delay(50);
		digitalWrite(RE, LOW);
		digitalWrite(LE, HIGH);
		delay(50);
		digitalWrite(LE, LOW);
		PORTD |= (1<<5);
		delay(50);
		PORTD &= ~(1<<5);
	}
	delay(100);
	digitalWrite(LE, HIGH);
	digitalWrite(RE, HIGH);
	delay(100);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);
	delay(100);
	digitalWrite(LE, HIGH);
	digitalWrite(RE, HIGH);
	delay(100);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);

	*(uint16_t *)0x0800 = 0x7777;
	wdt_enable(WDTO_250MS);
}

void Bot::afterStart(){
	// UUID - Load from or save to eeprom
	byte delimiter = eeprom_read_byte((byte *)QB_UUID_SIZE);
	// If the delimer is found, load it...
	if(!Bot::forceSaveUuid && delimiter == (byte)REPORT_UUID_DELIMITER){
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			Bot::uuid[i] = eeprom_read_byte((byte*)i);
		}
	}
	else{
		// If not, save it...
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			eeprom_write_byte((byte *)i, (byte) Bot::uuid[i]);
		}
		eeprom_write_byte((byte *)QB_UUID_SIZE, (byte)REPORT_UUID_DELIMITER);
	}

	wdt_disable();
	wdt_reset();
	*(uint16_t *)0x0800 = 0x0000;
}

void Bot::addNode(Node * node){
	if(Bot::nodePosition(node) != -1) return;
	Bot::nodes.push(node);
}
void Bot::removeNode(Node * node){
	if(Bot::nodePosition(node) == -1) return;
	Bot::nodes.pop(node);
}
int Bot::nodePosition(Node * node){
	for(unsigned int i=0; i<Bot::nodes.size(); i++){
		if(Bot::nodes[i] == node) return i;
	}
	return -1;
}

void Bot::addUpdatable(Updatable * updatable){
	if(Bot::updatablePosition(updatable) != -1) return;
	Bot::updatables.push(updatable);
}
void Bot::removeUpdatable(Updatable * updatable){
	if(Bot::updatablePosition(updatable) == -1) return;
	Bot::updatables.pop(updatable);
}
int Bot::updatablePosition(Updatable * updatable){
	for(unsigned int i=0; i<Bot::updatables.size(); i++){
		if(Bot::updatables[i] == updatable) return i;
	}
	return -1;
}

void Bot::addInterruptUpdatable(InterruptUpdatable * interruptUpdatable){
	if(Bot::interruptUpdatablePosition(interruptUpdatable) != -1) return;
	Bot::interruptUpdatables.push(interruptUpdatable);
}
void Bot::removeInterruptUpdatable(InterruptUpdatable * interruptUpdatable){
	if(Bot::interruptUpdatablePosition(interruptUpdatable) == -1) return;
	Bot::interruptUpdatables.pop(interruptUpdatable);
}
int Bot::interruptUpdatablePosition(InterruptUpdatable * interruptUpdatable){
	for(unsigned int i=0; i<Bot::interruptUpdatables.size(); i++){
		if(Bot::interruptUpdatables[i] == interruptUpdatable) return i;
	}
	return -1;
}

void Bot::update(){
	Bot::frames++;
	Bot::dtMicros = ::micros() - Bot::micros;
	Bot::micros = ::micros();
	Bot::millis = ::millis();
	Bot::seconds = Bot::millis * 0.001;

	for(unsigned int i=0; i<Bot::updatables.size(); i++){
		Bot::updatables[i]->update();
	}

	// Send serial reportis
	if(Bot::serialReportEnabled && Bot::millis >= Bot::reportMillisTick){
		Bot::reportMillisTick += REPORT_INTERVAL_MILLIS;
		// Start delimiter
		Serial.write((byte)REPORT_START_DELIMITER);

		// UUID --------
		// UUID is not printed on every tick
		if(Bot::reportMillisTick % (REPORT_INTERVAL_MILLIS * REPORT_UUID_INTERVAL_TICKS) == 0)
			Serial.write((uint8_t*)Bot::uuid, QB_UUID_SIZE);
		Serial.write((byte)REPORT_UUID_DELIMITER); // delimiter
		// Number of nodes
		Serial.write((byte)Bot::nodes.size());
		Serial.write((byte)REPORT_NUMBER_OF_NODES_DELIMITER);  // delimiter
		// Content
		for(unsigned int i=0; i<Bot::nodes.size(); i++){
			Bot::nodes[i]->serialReport();
			Serial.write((byte)REPORT_NODE_CONTENT_DELIMITER); // delimiter
		}
		// End delimiter
		Serial.write((byte)REPORT_END_DELIMITER);
	}
}

volatile void Bot::interruptUpdate(){
	for(unsigned int i=0; i<Bot::interruptUpdatables.size(); i++){
		Bot::interruptUpdatables[i]->interruptUpdate();
	}

	Bot::interruptCount++;
	if(interruptCount >= INTERUPT_COUNT_OVERFLOW){
		Bot::interruptCount = 0;
	}
}
// Keyboard management ---------------------------------------------------------
void Bot::pressKey(byte key){
	Keyboard.press(key);
};
void Bot::releaseKey(byte key){
	Keyboard.release(key);
};
void Bot::releaseAllKeys(){
	Keyboard.releaseAll();
};

// Utils -----------------------------------------------------------------------
float Bot::map(float x, float inMin, float inMax, float outMin, float outMax){
	float result = ((x - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin;
	if(outMin < outMax){
		if(result < outMin) result = outMin;
		else if(result > outMax) result = outMax;
	}
	else{
		if(result > outMin) result = outMin;
		else if(result < outMax) result = outMax;
	}

	return result;
}
float Bot::minimum(float a, float b){
	return min(a,b);
}
float Bot::maximum(float a, float b){
	return max(a,b);
}

int Bot::locationToBackPin(int location){
	switch(location){
		case LL:
			return LLB;
		case RL:
			return RLB;
		case RA:
			return RAB;
		case H:
			return HB;
		case LA:
			return LAB;
		default:
			return NO_LOCATION;
	}
};
int Bot::locationToFrontPin(int location){
	switch(location){
		case LL:
			return LLF;
		case RL:
			return RLF;
		case RA:
			return RAF;
		case H:
			return HF;
		case LA:
			return LAF;
		default:
			return NO_LOCATION;
	}
};
