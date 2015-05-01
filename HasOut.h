#ifndef HasOut_h
#define HasOut_h

#include "Node.h"

class OutputFloat;

template <class T>
class HasOut{
	public:
		HasOut(Node * node){}
		OutputFloat out;
};

#endif