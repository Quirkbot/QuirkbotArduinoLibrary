#include "Bot.h"


std::vector <BaseNode *> Bot::nodes = std::vector<BaseNode *>();
std::vector <Updatable *> Bot::updatables = std::vector<Updatable *>();
volatile unsigned long Bot::micros = 0;
volatile float Bot::millis = 0;
volatile float Bot::seconds = 0;
volatile unsigned long Bot::frames = 0;



void Bot::addNode(BaseNode * node){
	int position = Bot::nodePosition(node);
	if(position != -1) return;
	Bot::nodes.push_back(node);
}
void Bot::removeNode(BaseNode * node){
	int position = Bot::nodePosition(node);
	if(position == -1) return;
	Bot::nodes.erase (Bot::nodes.begin()+position);
}
int Bot::nodePosition(BaseNode * node){
	for(int i=0; i<Bot::nodes.size(); i++){
		if(Bot::nodes[i] == node) return i;
	}
	return -1;
}

void Bot::addUpdatable(Updatable * updatable){
	int position = Bot::updatablePosition(updatable);
	if(position != -1) return;
	Bot::updatables.push_back(updatable);
}
void Bot::removeUpdatable(Updatable * updatable){
	int position = Bot::updatablePosition(updatable);
	if(position == -1) return;
	Bot::updatables.erase (Bot::updatables.begin()+position);
}
int Bot::updatablePosition(Updatable * updatable){
	for(int i=0; i<Bot::updatables.size(); i++){
		if(Bot::updatables[i] == updatable) return i;
	}
	return -1;
}

void Bot::update(){
	Bot::frames++;
	Bot::micros += BOT_TIME_INCREMENT_MICROS;
	Bot::millis += BOT_TIME_INCREMENT_MILLIS;
	Bot::seconds += BOT_TIME_INCREMENT_SECONDS;
	
	for(int i=0; i<Bot::updatables.size(); i++){
		Bot::updatables[i]->update();
	}
}