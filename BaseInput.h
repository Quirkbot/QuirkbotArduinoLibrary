#ifndef BaseInput_h_
#define BaseInput_h_

class Node;

class BaseInput{
	friend class Node;
	public:
	virtual ~BaseInput(){}

	protected:
	Node * node;
};

#endif
