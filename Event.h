#ifndef Event_h_
#define Event_h_

#include <vector>

template <class T>
class Input;

template <class T>
class Event {
	public:

	typedef void (*VoidHandler)();
	typedef void (*TypedHandler)(T value);
	typedef void (Input<T>::*TypedInputHandler)(T value);
	typedef void (Input<T>::*VoidInputHandler)();
	
	void add(VoidHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		voidHandlers.push_back(handler);
	}
	void remove(VoidHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		voidHandlers.erase (voidHandlers.begin()+pos);
	}

	void add(TypedHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		typedHandlers.push_back(handler);
	}
	void remove(TypedHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		typedHandlers.erase (typedHandlers.begin()+pos);
	}

	void add(Input<T>* input, TypedInputHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		typedInputs.push_back(input);
		typedInputHandlers.push_back(handler);
	}
	void remove(TypedInputHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		typedInputs.erase (typedInputs.begin()+pos);
		typedInputHandlers.erase (typedInputHandlers.begin()+pos);
	}

	void add(Input<T>* input, VoidInputHandler handler){
		int pos = position(handler);
		if(pos != -1) return;
		voidInputs.push_back(input);
		voidInputHandlers.push_back(handler);
	}
	void remove(VoidInputHandler handler){
		int pos = position(handler);
		if(pos == -1) return;
		voidInputs.erase (voidInputs.begin()+pos);
		voidInputHandlers.erase (voidInputHandlers.begin()+pos);
	}
	
	void dispatch(T &value);
	void dispatch();
	
	private:
	int position(VoidHandler handler){
		for(int i=0; i<voidHandlers.size(); i++){
			if(voidHandlers[i] == handler) return i;
		}
		return -1;
	}
	int position(TypedHandler handler){
		for(int i=0; i<typedHandlers.size(); i++){
			if(typedHandlers[i] == handler) return i;
		}
		return -1;
	}
	int position(TypedInputHandler handler){
		for(int i=0; i<typedInputHandlers.size(); i++){
			if(typedInputHandlers[i] == handler) return i;
		}
		return -1;
	}
	int position(VoidInputHandler handler){
		for(int i=0; i<voidInputHandlers.size(); i++){
			if(voidInputHandlers[i] == handler) return i;
		}
		return -1;
	}

	std::vector<VoidHandler > voidHandlers;
	std::vector<TypedHandler > typedHandlers;
	std::vector<TypedInputHandler > typedInputHandlers;
	std::vector<VoidInputHandler > voidInputHandlers;
	std::vector<Input<T>* > typedInputs;
	std::vector<Input<T>* > voidInputs;
	
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