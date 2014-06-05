#ifndef Input_h_
#define Input_h_

#include "Node.h"
#include "Output.h"

class Node;
class Output;
class Input{
	friend class Node;
	public:

	Input();
	~Input();

	void connect(const float &number);
	void connect(Output &output);	

	Input & operator=(const float &number);
	Input & operator=(Output &output);
	operator float();

	float get();

	protected:

	void onOutputChange(float value);
	void clearOutput();

	float value;
	Node * node;
	Output * output;
};

#endif
