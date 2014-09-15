#ifndef Output_h_
#define Output_h_

#include "Event.h"
#include "Input.h"

template <class T>
class Event;

template <class T>
class Input;

template <class T>
class Output {
	public:

	Output(){
		value = T();
	}
	~Output(){
	}


	/**
	 * Handle for input connections.
	 **/
	/*void operator=(Input<T> &input){
		input.connect(*this);
	}*/
	void connect(Input<T> &input){
		input.connect(*this);
	}

	/**
	 * Getter and setter.
	 **/
	void set(T value){
		if(this->value == value) return;
		this->value = value;
		event.dispatch(value);
	}
	T get(){
		return value;
	}

	Event<T> event;

	private:

	T value;
};

#endif
