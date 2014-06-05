#include "Node.h"

unsigned int Node::ID_FACTORY = 0;

Node::Node(){
	id = Node::ID_FACTORY++;
	Bot::addNode(this);
}
Node::Node(unsigned int id){
	this->id = id;
	if(Node::ID_FACTORY < id)
		Node::ID_FACTORY = id;
	Bot::addNode(this);
}
Node::~Node(){
	Bot::removeNode(this);
}
void Node::registerInput(Input &input){
	inputs.push_back(&input);
	input.node = this;
}