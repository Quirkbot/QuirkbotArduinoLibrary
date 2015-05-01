#ifndef HasInputCollection_h_
#define HasInputCollection_h_

#include "Bot.h"
#include "InputFloat.h"
#include "OutputFloat.h"

template <class T>
class HasInputCollection{
	public:
	
	HasInputCollection(Node * node):
	inputCollectionNode(node){

	};

	// Getter
	InputFloat& operator[](unsigned int idx)  {
		while(items.size() <= idx){
			registerNewInput();
		}
		return *(items[idx]);
	};

	void add(OutputFloat &output){
		InputFloat * input = registerNewInput();
		input->connect(output);
	};
	void add(T &value){
		InputFloat * input = registerNewInput();
		(*input) = value;
	};
	void add(T value){
		InputFloat * input = registerNewInput();
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
	InputFloat * registerNewInput(){
		InputFloat * input = new InputFloat();
		inputCollectionNode->registerInput(*input);
		items.push(input);
		return input;
	}

	protected:
	Vector<InputFloat * > items;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif