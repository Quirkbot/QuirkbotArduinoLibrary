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
		while(inputCollection.size() <= idx){
			registerNewInput();
		}
		return *(inputCollection[idx]);
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
		while(inputCollection.size()){
			inputCollection[0]->disconnect();
			delete inputCollection[0];
			inputCollection.erase(0);
		}
	};

	private:
	Input<T> * registerNewInput(){
		Input<T> * input = new Input<T>();
		inputCollectionNode->registerInput(*input);
		inputCollection.push(input);
		return input;
	}

	protected:
	Vector<Input<T> * > inputCollection;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif