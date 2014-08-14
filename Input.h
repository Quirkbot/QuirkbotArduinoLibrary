#ifndef Input_h_
#define Input_h_

#include "Output.h"
#include "Streams.h"

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

	/**
	 * Preferred handle for primitive connections
	 **/
	void operator=(const T &value){
		handleValueConnection(value);
	}
	
	/**
	 * Preferred handle for output connections
	 **/
	void connect(const Output<T> &output){
		handleOutputConnection(output);
	}
	void disconnect(){
		clearOutput();
	}

	/**
	 * Function call style interface
	 **/
	void operator()(const T &value){
		handleValueConnection(value);
	}
	void operator()(const Output<T> &output){
		handleOutputConnection(output);
	}
	void operator()(){
		T value = this->value;
		handleValueConnection(value);
	}

	/**
	 * Getters
	 **/	
	T get(){
		return value;
	}
	operator T(){
		return get();
	}

	protected:
	void handleValueConnection(const T &value){
		clearOutput();
		onOutputChange(value);
	}
	void handleOutputConnection(const Output<T> &output){
		clearOutput();
		this->output = (Output<T>*) &output;
		this->output->event.add(this, &Input<T>::onOutputChange);
	}
	void onOutputChange(T value){
		this->value = value;
		if(node) node->onInternalInputChange(*this);
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
