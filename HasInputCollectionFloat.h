#ifndef HasInputCollectionFloat_h_
#define HasInputCollectionFloat_h_

#include "Bot.h"
#include "InputFloat.h"
#include "OutputFloat.h"

class HasInputCollectionFloat{
	public:
	
	HasInputCollectionFloat(Node * node);

	// Getter
	InputFloat& operator[](unsigned int idx);

	void add(OutputFloat &output);
	void add(float &value);
	void add(float value);
	void clear();

	private:
	InputFloat * registerNewInput();

	protected:
	Vector<InputFloat * > items;

	Node * inputCollectionNode;
	virtual void onItemsUpdated(){};


};

#endif