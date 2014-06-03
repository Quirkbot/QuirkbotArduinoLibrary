#include "BaseNode.h"

unsigned int BaseNode::ID_FACTORY = 0;

BaseNode::BaseNode(){
	id = BaseNode::ID_FACTORY++;
	Bot::addNode(this);
}
BaseNode::BaseNode(unsigned int id){
	this->id = id;
	if(BaseNode::ID_FACTORY < id)
		BaseNode::ID_FACTORY = id;
	Bot::addNode(this);
}
BaseNode::~BaseNode(){
	Bot::removeNode(this);
}