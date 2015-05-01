#include "Event.h"

void Event::add(VoidHandler handler){
	int pos = position(handler);
	if(pos != -1) return;
	voidHandlers.push(handler);
}
void Event::remove(VoidHandler handler){
	int pos = position(handler);
	if(pos == -1) return;
	voidHandlers.erase(pos);
}
void Event::add(TypedHandler handler){
	int pos = position(handler);
	if(pos != -1) return;
	typedHandlers.push(handler);
}
void Event::remove(TypedHandler handler){
	int pos = position(handler);
	if(pos == -1) return;
	typedHandlers.erase(pos);
}
void Event::add(InputFloat* input, TypedInputHandler handler){
	int pos = position(handler);
	if(pos != -1) return;
	typedInputs.push(input);
	typedInputHandlers.push(handler);
}
void Event::remove(TypedInputHandler handler){
	int pos = position(handler);
	if(pos == -1) return;
	typedInputs.erase(pos);
	typedInputHandlers.erase(pos);
}
void Event::add(InputFloat* input, VoidInputHandler handler){
	int pos = position(handler);
	if(pos != -1) return;
	voidInputs.push(input);
	voidInputHandlers.push(handler);
}
void Event::remove(VoidInputHandler handler){
	int pos = position(handler);
	if(pos == -1) return;
	voidInputs.erase(pos);
	voidInputHandlers.erase(pos);
}	
int Event::position(VoidHandler handler){
	for(int i=0; i<voidHandlers.size(); i++){
		if(&(voidHandlers[i]) == &handler) return i;
	}
	return -1;
}
int Event::position(TypedHandler handler){
	for(int i=0; i<typedHandlers.size(); i++){
		if(&(typedHandlers[i]) == &handler) return i;
	}
	return -1;
}
int Event::position(TypedInputHandler handler){
	for(int i=0; i<typedInputHandlers.size(); i++){
		if(&(typedInputHandlers[i]) == &handler) return i;
	}
	return -1;
}
int Event::position(VoidInputHandler handler){
	for(int i=0; i<voidInputHandlers.size(); i++){
		if(&(voidInputHandlers[i]) == &handler) return i;
	}
	return -1;
}
void Event::dispatch(float &value){
	for(int i=0; i<voidHandlers.size(); i++){
		voidHandlers[i]();
	}
	for(int i=0; i<typedHandlers.size(); i++){
		typedHandlers[i](value);
	}
	for(int i=0; i<typedInputHandlers.size(); i++){
		(typedInputs[i]->*(typedInputHandlers[i]))(value);
	}
	for(int i=0; i<voidInputHandlers.size(); i++){
		(voidInputs[i]->*(voidInputHandlers[i]))();
	}
}
void Event::dispatch(){
	float a;
	for(int i=0; i<voidHandlers.size(); i++){
		voidHandlers[i]();
	}
	for(int i=0; i<typedHandlers.size(); i++){
		typedHandlers[i](a);
	}
	for(int i=0; i<typedInputHandlers.size(); i++){
		(typedInputs[i]->*(typedInputHandlers[i]))(a);
	}
	for(int i=0; i<voidInputHandlers.size(); i++){
		(voidInputs[i]->*(voidInputHandlers[i]))();
	}
}