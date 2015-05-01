#include "HasInputCollectionFloat.h"

HasInputCollectionFloat::HasInputCollectionFloat(Node * node):
inputCollectionNode(node){

};
InputFloat& HasInputCollectionFloat::operator[](unsigned int idx)  {
	while(items.size() <= idx){
		registerNewInput();
	}
	return *(items[idx]);
};
void HasInputCollectionFloat::add(OutputFloat &output){
	InputFloat * input = registerNewInput();
	input->connect(output);
};
void HasInputCollectionFloat::add(float &value){
	InputFloat * input = registerNewInput();
	(*input) = value;
};
void HasInputCollectionFloat::add(float value){
	InputFloat * input = registerNewInput();
	(*input) = value;		
};
void HasInputCollectionFloat::clear(){
	while(items.size()){
		items[0]->disconnect();
		delete items[0];
		items.erase(0);
	}
};
InputFloat * HasInputCollectionFloat::registerNewInput(){
	InputFloat * input = new InputFloat();
	inputCollectionNode->registerInput(*input);
	items.push(input);
	return input;
}