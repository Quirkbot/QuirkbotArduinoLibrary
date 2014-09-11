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
	 * Handle for both, primitives and outputs connections.
	 * If called on a primitive, clearOutput will also be called, causing the
	 * input to disconnect from a previously connected output.
	 **/
	void operator=(const T &value){
		handleValueConnection(value);
	}
	void operator=(const Output<T> &output){
		handleOutputConnection(output);
	}
	void connect(const T &value){
		clearOutput();
		handleValueConnection(value);
	}
	void connect(const Output<T> &output){
		handleOutputConnection(output);
	}

	/**
	 * Remove connections
	 **/
	void disconnect(){
		clearOutput();
	}

	/**
	 * Getter
	 **/	
	T get(){
		return value;
	}

	protected:
	void handleValueConnection(const T &value){
		/**
		 * Should value connections really clear the output? Maybe it's better
		 * if they keep the connection, so we know that every time we connect to
		 * an output, the only way to disconnect is by explicitly calling the 
		 * 'disconnect' method.
		 **/
		//clearOutput();
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
