#include "Updatable.h"

Updatable::Updatable(){
	Bot::updatables.add(this);
}
Updatable::~Updatable(){
	Bot::updatables.remove(this);
}
