#include "Node.h"

unsigned int Node::ID_FACTORY = 0;

Node::Node(){
	id = Node::ID_FACTORY++;
	Bot::nodes.add(this);
}
Node::Node(unsigned int id){
	this->id = id;
	if(Node::ID_FACTORY < id)
		Node::ID_FACTORY = id;
	Bot::nodes.add(this);
}
Node::~Node(){
	Bot::nodes.remove(this);
}
void Node::registerInput(BaseInput &input){
	input.node = this;
}
void Node::registerInputCollection(InputCollection &inputCollection){
	inputCollection.node = this;
}
