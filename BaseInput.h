#ifndef BaseInput_h_
#define BaseInput_h_

#include "Node.h"
class Node;

class BaseInput{
	friend class Node;
	public:
	virtual ~BaseInput(){}

	protected:
	Node * node;
};

#endif
