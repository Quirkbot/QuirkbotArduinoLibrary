#ifndef Event_h_
#define Event_h_

#include <vector>

template <class T>
class Input;

template <class T>
class Event {
	public:

	typedef void (*Handler)(T value);
	typedef void (Input<T>::*InputHandler)(T value);
	
	void add(Handler handler){
		int pos = position(handler);
		if(pos != -1) return;
		handlers.push_back(handler);
	}

	void remove(Handler handler){
		int pos = position(handler);
		if(pos == -1) return;
		handlers.erase (handlers.begin()+pos);
	}

	void add(Input<T>* input, InputHandler inputHandler){
		int pos = position(inputHandler);
		if(pos != -1) return;
		inputs.push_back(input);
		inputHandlers.push_back(inputHandler);
	}

	void remove(InputHandler inputHandler){
		int pos = position(inputHandler);
		if(pos == -1) return;
		inputs.erase (inputs.begin()+pos);
		inputHandlers.erase (inputHandlers.begin()+pos);
	}
	
	void dispatch(T &value);
	void dispatch();
	
	private:
	int position(Handler handler){
		for(int i=0; i<handlers.size(); i++){
			if(handlers[i] == handler) return i;
		}
		return -1;
	}
	int position(InputHandler  inputHandler){
		for(int i=0; i<inputHandlers.size(); i++){
			if(inputHandlers[i] == inputHandler) return i;
		}
		return -1;
	}

	std::vector<Handler > handlers;
	std::vector<InputHandler > inputHandlers;
	std::vector<Input<T>* > inputs;
	
};
template <class T>
void Event<T>::dispatch(T &value){
	for(int i=0; i<handlers.size(); i++){
		handlers[i](value);
	}
	for(int i=0; i<inputHandlers.size(); i++){
		(inputs[i]->*(inputHandlers[i]))(value);
	}
}
template <class T>
void Event<T>::dispatch(){
	T a;
	for(int i=0; i<handlers.size(); i++){
		handlers[i](a);
	}
	for(int i=0; i<inputHandlers.size(); i++){
		(inputs[i]->*(inputHandlers[i]))(a);
	}
}

#endif