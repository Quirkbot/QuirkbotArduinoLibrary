#ifndef Streams_h
#define Streams_h

#include "Node.h"

template <class T>
class Input;

template <class T>
class Output;

template <class T>
class HasOut;

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

template <class T>
class HasOut{
	public:
		HasOut(Node * node){}
		Output<T> out;
};

#endif