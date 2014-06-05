#ifndef InputEvent_Node_h_
#define InputEvent_Node_h_

#include <vector>

#include "Node.h";

class Input;
class Node;

typedef void (Node::*InputEventHandler_Node)(Input&);

class InputEvent_Node {
	friend class Node;
	
	public:

	void add(Node* input, InputEventHandler_Node handler);
	void remove(InputEventHandler_Node handler);
	void dispatch(Input& value);
	int handlerPosition(InputEventHandler_Node handler);
	
	private:
	// These lists must be in sync
	std::vector<Node*> inputs;
	std::vector<InputEventHandler_Node> handlers;
};

#endif
