#ifndef HasInputCollection_h_
#define HasInputCollection_h_

#include "Bot.h"
#include "Input.h"
#include "Output.h"

template <class T>
class HasInputCollection{
	public:
	
	HasInputCollection(Node * node):
	inputCollectionNode(node){

	};

	// Getter
	Input<T>& operator[](unsigned int idx)  {
		while(items.size() <= idx){
			registerNewInput();
		}
		return *(items[idx]);
	};

	void add(Output<T> &output){
		Input<T> * input = registerNewInput();
		input->connect(output);
	};
	void add(T &value){
		Input<T> * input = registerNewInput();
		(*input) = value;
	};
	void add(T value){
		Input<T> * input = registerNewInput();
		(*input) = value;		
	};
	void clear(){
		while(items.size()){
			items[0]->disconnect();
			delete items[0];
			items.erase(0);
		}
	};

	private:
	Input<T> * registerNewInput(){
		Input<T> * input = new Input<T>();
		inputCollectionNode->registerInput(*input);
		items.push(input);
		return input;
	}

	protected:
	Vector<Input<T> * > items;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif