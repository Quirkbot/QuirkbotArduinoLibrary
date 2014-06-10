#ifndef Input_h_
#define Input_h_

#include "Node.h"
#include "BaseInput.h"
#include "Output.h"

class Node;

template <class T>
class Input : public BaseInput{
	friend class Node;
	public:

	~Input(){
		clearOutput();
	}

	void set(const T &value){
		clearOutput();
		onOutputChange(value);
	}
	void operator=(const T &value){
		set(value);
	}
	void operator()(T &value){
		set(value);
	}
	void connect(Output<T> &output){
		clearOutput();
		this->output = &output;
		this->output->changed.add(this, &Input<T>::onOutputChange);
	}	
	void operator=(Output<T> &output){
		connect(output);
	}
	void operator()(Output<T> &output){
		connect(output);
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
		if(output)
			output->changed.remove(&Input<T>::onOutputChange);
	}

	T value;
	Output<T> * output;
};

#endif
