#ifndef Node_h_
#define Node_h_

#include "Bot.h"
#include "BaseInput.h"

class Bot;
class BaseInput;

class Node{
	public:
	
	Node();
	Node(unsigned int id);
	~Node();


	void registerInput(BaseInput &input);
	virtual void onInternalInputChange(BaseInput &internalInput){};

	virtual void serialReport(){};
	
	protected:
	unsigned int id;
	

	private:

	static unsigned int ID_FACTORY;
};

#endif
