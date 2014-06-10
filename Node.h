#ifndef Node_h_
#define Node_h_

#include <vector>
#include "Bot.h"
#include "BaseInput.h"

class Node{
	public:
	
	Node();
	Node(unsigned int id);
	~Node();


	void registerInput(BaseInput &input);
	virtual void onInternalInputChange(BaseInput &input){};

	
	protected:
	unsigned int id;
	std::vector<const BaseInput*> inputs;	

	private:

	static unsigned int ID_FACTORY;
};

#endif
