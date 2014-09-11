#ifndef HasIn_h
#define HasIn_h

#include "Node.h"

template <class T>
class Input;

template <class T>
class HasIn{
	public:
		HasIn(Node * node):
		streamNode(node){
			streamNode->registerInput(in);
			in = 0;
		}
	
		Input<T> in;

		private:

		Node * streamNode;
};

#endif