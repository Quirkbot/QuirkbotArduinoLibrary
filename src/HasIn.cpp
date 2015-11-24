#include "HasIn.h"

HasIn::HasIn(Node * node):
streamNode(node){
	streamNode->registerInput(in);
	in = 0;
}
HasIn::~HasIn(){}
