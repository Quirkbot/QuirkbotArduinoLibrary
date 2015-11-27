#ifndef HasIn_h
#define HasIn_h

#include "Node.h"
#include "Input.h"

class HasIn{
	public:
	HasIn(Node * node);
	~HasIn();

	Input in;

	private:

	Node * streamNode;
};

#endif
