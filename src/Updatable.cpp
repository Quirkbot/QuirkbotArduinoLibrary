#include "Updatable.h"

Updatable::Updatable(){
	Bot::addUpdatable(this);
}
Updatable::~Updatable(){
	Bot::removeUpdatable(this);
}