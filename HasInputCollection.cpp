#include "HasInputCollection.h"

HasInputCollection::HasInputCollection(Node * node):
inputCollectionNode(node){

};
Input& HasInputCollection::operator[](unsigned int idx)  {
	while(items.size() <= idx){
		registerNewInput();
	}
	return *(items[idx]);
};
void HasInputCollection::add(Output &output){
	Input * input = registerNewInput();
	input->connect(output);
};
void HasInputCollection::add(float &value){
	Input * input = registerNewInput();
	(*input) = value;
};
void HasInputCollection::add(float value){
	Input * input = registerNewInput();
	(*input) = value;		
};
void HasInputCollection::clear(){
	while(items.size()){
		items[0]->disconnect();
		delete items[0];
		items.erase(0);
	}
};
Input * HasInputCollection::registerNewInput(){
	Input * input = new Input();
	inputCollectionNode->registerInput(*input);
	items.push(input);
	return input;
}