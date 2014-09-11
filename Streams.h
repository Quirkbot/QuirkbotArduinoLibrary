#ifndef Streams_h
#define Streams_h

#include "Node.h"

template <class T>
class Input;

template <class T>
class Output;

template <class T>
class OutputStream;

template <class T>
class InputStream{
	public:
		InputStream(Node * node):
		streamNode(node){
			streamNode->registerInput(in);
			in = 0;
		}
	
		Input<T> in;

		private:

		Node * streamNode;
};

template <class T>
class OutputStream{
	public:
		OutputStream(Node * node){}
		Output<T> out;
};

template <class T>
class InputOutputStream :public InputStream<T>, public OutputStream<T>{
	public:
		InputOutputStream(Node * node):
		InputStream<T>(node),
		OutputStream<T>(node)
		{}
};

#endif