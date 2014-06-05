#ifndef Node_h_
#define Node_h_

#include <vector>
#include "Bot.h"
#include "Input.h"

class Input;

class Node{
	friend class Input;
	public:
	
	Node();
	Node(unsigned int id);
	~Node();
	
	protected:

	void registerInput(Input &input);
	virtual void onInternalInputChange(Input &input){};

	unsigned int id;
	std::vector<const Input*> inputs;	

	private:

	static unsigned int ID_FACTORY;
};

#endif
