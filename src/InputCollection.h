#ifndef InputCollection_h_
#define InputCollection_h_

#include "Bot.h"
#include "Input.h"
#include "Node.h"
#include "Vector.h"

class Node;
class Output;
class Input;

class InputCollection{
	friend class Node;
	public:

	InputCollection();
	~InputCollection();

	// Getter
	Input& operator[](unsigned int idx);

	void add(Output &output);
	void add(float &value);
	void add(float value);
	void clear();

	Vector<Input*> collection;

	protected:
	Node * node;

	private:
	Input * registerNewInput();
};

#endif
