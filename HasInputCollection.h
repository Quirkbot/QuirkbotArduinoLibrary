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

	void add(Output<T> &output){
		Input<T> * input = new Input<T>();
		inputCollectionNode->registerInput(*input);
		input->connect(output);
		inputCollection.push(input);
	};
	void add(T &value){
		Input<T> * input = new Input<T>();
		inputCollectionNode->registerInput(*input);
		(*input) = value;
		inputCollection.push(input);
	};
	void add(T value){
		Input<T> * input = new Input<T>();
		inputCollectionNode->registerInput(*input);
		(*input) = value;
		inputCollection.push(input);
	};
	void clear(){
		while(inputCollection.size()){
			inputCollection[0]->disconnect();
			delete inputCollection[0];
			inputCollection.erase(0);
		}
	};

	protected:
	Vector<Input<T> * > inputCollection;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif