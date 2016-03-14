#include <avr/eeprom.h>
#include "Bot.h"

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
void Bot::start(){
	// Enable the watchdog and set the magic key right on the beggining, so in
	// case the program crashes (eg. ram overlfow), it will return to booloader
	// mode, allowing the user to upload new code again.
	*(uint16_t *)0x0800 = 0x7777;
	wdt_enable(WDTO_2S);

	// Start Serial
	Serial.begin(115200);

	// Start HID
	Keyboard.begin();
	Mouse.begin();

	// Startup animation
	pinMode(LE, OUTPUT);
	pinMode(RE, OUTPUT);
	DDRD |= (1<<5);
	DDRB |= (1<<0);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);
	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);
	for (int i = 0; i < 2; i++) {
		wdt_reset();

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
	wdt_reset();
	delay(100);
	digitalWrite(LE, HIGH);
	digitalWrite(RE, HIGH);

	wdt_reset();
	delay(100);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);

	wdt_reset();
	delay(100);
	digitalWrite(LE, HIGH);
	digitalWrite(RE, HIGH);

	wdt_reset();
	delay(100);
	digitalWrite(LE, LOW);
	digitalWrite(RE, LOW);
}
void Bot::afterStart(){
	// Build the UUID

	// If the Bot::forceSaveUuid flag is not set, read the uuid from MEMORY.
	if(!Bot::forceSaveUuid){
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			Bot::uuid[i] = eeprom_read_byte((byte*)i);
		}
	}

	// ALWAYS overwrite the "header" of Bot::uuid
	// The first 2 bytes are the bootloader id
	uint16_t bootloaderId = Bot::getBootloaderId();
	Bot::uuid[0] = bootloaderId >> 8;
	Bot::uuid[1] = bootloaderId & 0xFF;

	// The foolowing 2 bytes are the bootloader version
	uint16_t bootloaderVersion = Bot::getBootloaderVersion();
	Bot::uuid[2] = bootloaderVersion >> 8;
	Bot::uuid[3] = bootloaderVersion & 0xFF;

	// Make that no part of the UUID matches the reserved serial delimiters
	for (int i = 0; i < QB_UUID_SIZE; ++i){
		if(    Bot::uuid[i] == REPORT_START_DELIMITER
			|| Bot::uuid[i] == REPORT_END_DELIMITER
			|| Bot::uuid[i] == REPORT_UUID_DELIMITER
			|| Bot::uuid[i] == REPORT_NUMBER_OF_NODES_DELIMITER ){
				Bot::uuid[i] = 0;
			}
	}

	// If the Bot::forceSaveUuid flag is set, save whatever is on Bot::uuid to EEPROM
	if(Bot::forceSaveUuid){
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			eeprom_write_byte((byte *)i, (byte) Bot::uuid[i]);
		}
		eeprom_write_byte((byte *)QB_UUID_SIZE, (byte)REPORT_UUID_DELIMITER);
	}

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

	serialTask();
	midiTask();

	wdt_reset();
}

void Bot::serialTask(){
	// Send serial report
	if(Bot::serialReportEnabled && Bot::millis >= Bot::reportMillisTick){
		Bot::reportMillisTick += REPORT_INTERVAL_MILLIS;
		// Start delimiter
		Serial.write((byte)REPORT_START_DELIMITER);

		// UUID --------
		// UUID is not printed on every tick
		if(Bot::reportMillisTick % (REPORT_INTERVAL_MILLIS * REPORT_UUID_INTERVAL_TICKS) == 0){
			Serial.write((uint8_t*)Bot::uuid, QB_UUID_SIZE);

		}
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

void Bot::midiTask(){
	// Handle incoming messages
	midiEventPacket_t midiPacket;
	midiPacket = MidiUSB.read();
	if (midiPacket.header != 0){
		// Parse the message
		uint8_t command;
		uint8_t byte1;
		uint8_t byte2;
		uint16_t data;
		Bot::midiToData(&midiPacket, &command, &byte1, &byte2);

		// Enter bootloader mode
		if(command == BotMIDICommands::EnterBootloader){
			Bot::enterBootloader();
		}
		// Get the UUID
		else if(command == BotMIDICommands::ReadUUID){
			// Send it 2 bytes at the time
			for (uint8_t i = 0; i < QB_UUID_SIZE; i +=2 ) {
				command = BotMIDICommands::Data;
				byte1 = Bot::uuid[i];
				byte2 = Bot::uuid[i + 1];
				Bot::sendMidiData(command, byte1, byte2);
			}
		}
		// Echo a sync acknowledgment
		else if(command ==  BotMIDICommands::Sync){
			Bot::sendMidiData(command, byte1, byte2);
		}
	}
}
void Bot::sendMidiData(uint8_t command, uint8_t byte1, uint8_t byte2){
	midiEventPacket_t midiPacket;
	dataToMidi(command, byte1, byte2, &midiPacket);
	MidiUSB.sendMIDI(midiPacket);
	MidiUSB.flush();
}
void Bot::dataToMidi(uint8_t command, uint8_t byte1, uint8_t byte2, midiEventPacket_t * packet){
	packet->byte1 = (command << 2) | (byte1 >> 6) | 0x80;
	packet->byte2 = (byte2 >> 7) | ((byte1 & 0x3F) << 1);
	packet->byte3 =  byte2 & 0x7F;
	packet->header = packet->byte1 >> 4;
}
void Bot::midiToData(midiEventPacket_t *packet, uint8_t *command, uint8_t *byte1, uint8_t *byte2){
	*command =  (packet->byte1 - 0x80) >> 2;
	*byte1   = ((packet->byte1 & 0x3) << 6) | (packet->byte2 >> 1);
	*byte2   = ((packet->byte2 & 0x1) << 7) |  packet->byte3;
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

// Bootloader Support ----------------------------------------------------------
uint16_t Bot::readFlashWord(uint16_t address){
	uint16_t word = pgm_read_byte((void *)address);
	word += pgm_read_byte((void *)address+1) << 8;
	return word;
};
uint16_t Bot::getBootloaderId(){
	return Bot::readFlashWord(BOOTLOADER_ID_SIGNATURE_START);
};
uint16_t Bot::getBootloaderVersion(){
	return Bot::readFlashWord(BOOTLOADER_VERSION_SIGNATURE_START);
};
void Bot::enterBootloader(){
	cli();
	// Set the bootloader key to the magic value and force a reset
	*(uint16_t *)0x0800 = 0x7777;
	wdt_enable(WDTO_120MS);
	for (;;);
}

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

int Bot::locationToAnalogPin(int location){
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
		case LLB:
			return LLB;
		case RLB:
			return RLB;
		case RAB:
			return RAB;
		case HB:
			return HB;
		case LAB:
			return LAB;
		case BP1:
			return BP1;
		case BP2:
			return BP2;
		default:
			return NO_LOCATION;
	}
};
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
