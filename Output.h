#ifndef Output_h_
#define Output_h_

#include "Event.h"
//#include "Mathematics.h"

template <class T>
class Event;

template <class T>
class Output {
	public:

	Output(){
		//addition = NULL;
	}
	~Output(){
		//if(addition) delete addition;
	}

	void set(T value){
		if(this->value == value) return;
		this->value = value;
		event.dispatch(value);
	}
	void operator=(T value){
		set(value);
	}	

	T get(){
		return value;
	}
	operator T(){
		return get();
	}

	/*Output<T>& operator+(const T &value){
		if(!addition) addition = new Addition();
		(*addition)(*this, value);
		return addition->Output;
	}*/

	Event<T> event;

	private:

	T value;

	//Addition * addition;	
};

#endif
