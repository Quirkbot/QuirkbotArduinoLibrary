#include "Bot.h"


Vector <Node *> Bot::nodes = Vector<Node *>();
Vector <Updatable *> Bot::updatables = Vector<Updatable *>();
volatile unsigned long Bot::micros = 0;
volatile float Bot::millis = 0;
volatile float Bot::seconds = 0;
volatile unsigned long Bot::frames = 0;



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
	Bot::micros += BOT_TIME_INCREMENT_MICROS;
	Bot::millis += BOT_TIME_INCREMENT_MILLIS;
	Bot::seconds += BOT_TIME_INCREMENT_SECONDS;
	
	for(unsigned int i=0; i<Bot::updatables.size(); i++){
		Bot::updatables[i]->update();
	}
}