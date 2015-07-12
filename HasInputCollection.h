#ifndef HasInputCollection_h_
#define HasInputCollection_h_

#include "Bot.h"
#include "Input.h"
#include "Output.h"

class HasInputCollection{
	public:
	
	HasInputCollection(Node * node);

	// Getter
	Input& operator[](unsigned int idx);

	void add(Output &output);
	void add(float &value);
	void add(float value);
	void clear();

	private:
	Input * registerNewInput();

	protected:
	Vector<Input * > items;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif