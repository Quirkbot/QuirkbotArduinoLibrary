#ifndef CollectionNode_h_
#define CollectionNode_h_

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"

template <class T>
class CollectionNode:
public Node
{
	public:
	
	CollectionNode(){};

	void add(Output<T> &output){
		Input<T> * input = new Input<T>();
		registerInput(*input);
		input->connect(output);
		items.push(input);
	};
	void add(T &value){
		Input<T> * input = new Input<T>();
		registerInput(*input);
		(*input) = value;
		items.push(input);
	};
	void add(T value){
		Input<T> * input = new Input<T>();
		registerInput(*input);
		(*input) = value;
		items.push(input);
	};
	void clear(){
		while(items.size()){
			items[0]->disconnect();
			delete items[0];
			items.erase(0);
		}
	};

	protected:
	Vector<Input<T> * > items;

	virtual void onItemsUpdated(){};

};

#endif