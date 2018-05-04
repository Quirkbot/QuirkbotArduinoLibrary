#ifndef Node_h_
#define Node_h_

#include "Bot.h"
#include "BaseInput.h"
#include "InputCollection.h"

class Bot;
class BaseInput;
class InputCollection;

class Node{
	public:

	Node();
	Node(unsigned int id);
	~Node();


	void registerInput(BaseInput& input);
	void registerInputCollection(InputCollection& inputCollection);
	virtual void onInternalInputChange(BaseInput& /*internalInput*/){}; // <-- unnamed parameter to avoid compiler warnings

	protected:
	unsigned int id;


	private:

	static unsigned int ID_FACTORY;
};

#endif
