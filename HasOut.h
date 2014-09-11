#ifndef HasOut_h
#define HasOut_h

#include "Node.h"

template <class T>
class Output;

template <class T>
class HasOut{
	public:
		HasOut(Node * node){}
		Output<T> out;
};

#endif