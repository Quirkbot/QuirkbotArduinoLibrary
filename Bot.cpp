#include <avr/eeprom.h>
#include "Bot.h"


Vector <Node *> Bot::nodes = Vector<Node *>();
Vector <Updatable *> Bot::updatables = Vector<Updatable *>();
byte Bot::uuid[QB_UUID_SIZE] = {0x00};
volatile unsigned long Bot::frames = 0;
volatile unsigned long Bot::dtMicros = 0;
volatile unsigned long Bot::micros = 0;
volatile unsigned long Bot::millis = 0;
volatile float Bot::seconds = 0;
unsigned long Bot::reportMillisTick = 0;
bool Bot::serialReportEnabled = true;

void Bot::setup(){
	// Start serial
 	Serial.begin(115200);

 	// Start Keyboard
 	Keyboard.begin();
 	
 	// Force mouth to turn off (only used if you have to use the LillyPad USB)
 	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	// Load (or create) UUID from eeprom
	byte delimiter = eeprom_read_byte((uint8_t*)QB_UUID_SIZE);
	if(delimiter == '_'){
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			Bot::uuid[i] = eeprom_read_byte((uint8_t*)i);
		}
	}
	else{
		for (int i = 0; i < QB_UUID_SIZE; ++i){
			
			randomSeed(analogRead(A0) + analogRead(A1) +analogRead(A2) + analogRead(A3));
			switch(random(0,3)){
				case 0:
					Bot::uuid[i] = '0' + random(0,9);
					break;
				case 1:
					Bot::uuid[i] = 'a' + random(0,26);
					break;
				case 2:
					Bot::uuid[i] = 'A' + random(0,26);
					break;
			}
			eeprom_write_byte((uint8_t*) Bot::uuid[i], (uint8_t)i);
			delay(10);
		}
		eeprom_write_byte((uint8_t*)'_', (uint8_t)QB_UUID_SIZE);
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

void Bot::update(){
	Bot::frames++;
	Bot::dtMicros = ::micros() - Bot::micros;
	Bot::micros = ::micros();
	Bot::millis = ::millis();
	Bot::seconds = Bot::millis * 0.001;
	
	for(unsigned int i=0; i<Bot::updatables.size(); i++){
		Bot::updatables[i]->update();
	}

	// Send serial report every 100 millis
	if(Bot::serialReportEnabled && Bot::millis >= Bot::reportMillisTick){
		Bot::reportMillisTick += 100;

		// Start delimiter
		Serial.write('_');
		
		// UUID --------
		Serial.write((uint8_t*)Bot::uuid, QB_UUID_SIZE);
		Serial.write('='); // delimiter
		// Number of nodes
		Serial.write((byte)Bot::nodes.size());
		Serial.write(':');  // delimiter
		// Content
		for(unsigned int i=0; i<Bot::nodes.size(); i++){
			Bot::nodes[i]->serialReport();
			Serial.write('|'); // delimiter
		}		
		// End delimiter
		Serial.write('\n');
		
	}
}

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