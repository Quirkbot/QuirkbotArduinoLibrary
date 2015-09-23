#include "Quirkbot.h"


void setup(){
	Bot::beforeStart();
	start();
	Bot::afterStart();
}
void loop(){
	Bot::update();
}
