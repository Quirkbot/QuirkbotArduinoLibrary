#ifndef Input_h_
#define Input_h_

#include "Output.h"

class BaseInput;

template <class T>
class Output;

template <class T>
class Input : public BaseInput{
	friend class Node;
	public:

	Input(){
		output = NULL;
	}
	~Input(){
		clearOutput();
	}

	void connect(const T &value){
		clearOutput();
		onOutputChange(value);
	}
	void operator=(const T &value){
		connect(value);
	}
	void operator()(T &value){
		connect(value);
	}
	void operator()(){
		T value = this->value;
		connect(value);
	}
	void connect(Output<T> &output){
		clearOutput();
		this->output = &output;
		this->output->event.add(this, &Input<T>::onOutputChange);
	}	
	void operator=(Output<T> &output){
		connect(output);
	}
	void operator()(Output<T> &output){
		connect(output);
	}
	void disconnect(Output<T> &output){
		if(&output != this->output) return;
		clearOutput();
	}
	
	T get(){
		return value;
	}
	operator T(){
		return get();
	}

	protected:

	void onOutputChange(T value){
		this->value = value;
		node->onInternalInputChange(*this);
	}
	void clearOutput(){
		if(output){
			output->event.remove(&Input<T>::onOutputChange);
			output = NULL;
		}
	}

	T value;
	Output<T> * output;
};

#endif
