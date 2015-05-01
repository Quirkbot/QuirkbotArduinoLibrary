#ifndef Event_h_
#define Event_h_

#include "Vector.h"

class InputFloat;

template <class T>
class Event {
	public:

	typedef void (*VoidHandler)();
	typedef void (*TypedHandler)(T value);
	typedef void (InputFloat::*TypedInputHandler)(T value);
	typedef void (InputFloat::*VoidInputHandler)();
	
	void add(VoidHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		voidHandlers.push(handler);
	}
	void remove(VoidHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		voidHandlers.erase(pos);
	}

	void add(TypedHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		typedHandlers.push(handler);
	}
	void remove(TypedHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		typedHandlers.erase(pos);
	}

	void add(InputFloat* input, TypedInputHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		typedInputs.push(input);
		typedInputHandlers.push(handler);
	}
	void remove(TypedInputHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		typedInputs.erase(pos);
		typedInputHandlers.erase(pos);
	}

	void add(InputFloat* input, VoidInputHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		voidInputs.push(input);
		voidInputHandlers.push(handler);
	}
	void remove(VoidInputHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		voidInputs.erase(pos);
		voidInputHandlers.erase(pos);
	}
	
	void dispatch(T &value);
	void dispatch();
	
	private:
	int position(VoidHandler handler){
		for(int i=0; i<voidHandlers.size(); i++){
			if(&(voidHandlers[i]) == &handler) return i;
		}
		return -1;
	}
	int position(TypedHandler handler){
		for(int i=0; i<typedHandlers.size(); i++){
			if(&(typedHandlers[i]) == &handler) return i;
		}
		return -1;
	}
	int position(TypedInputHandler handler){
		for(int i=0; i<typedInputHandlers.size(); i++){
			if(&(typedInputHandlers[i]) == &handler) return i;
		}
		return -1;
	}
	int position(VoidInputHandler handler){
		for(int i=0; i<voidInputHandlers.size(); i++){
			if(&(voidInputHandlers[i]) == &handler) return i;
		}
		return -1;
	}

	Vector<VoidHandler > voidHandlers;
	Vector<TypedHandler > typedHandlers;
	Vector<TypedInputHandler > typedInputHandlers;
	Vector<VoidInputHandler > voidInputHandlers;
	Vector<InputFloat* > typedInputs;
	Vector<InputFloat* > voidInputs;
	
};
template <class T>
void Event<T>::dispatch(T &value){
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
template <class T>
void Event<T>::dispatch(){
	T a;
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

#endif