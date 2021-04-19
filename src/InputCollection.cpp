#include "InputCollection.h"

InputCollection::InputCollection(){
	node = NULL;
};
InputCollection::~InputCollection(){}
Input& InputCollection::get(unsigned int idx){
	while(collection.size() <= idx){
		registerNewInput();
	}
	return *(collection[idx]);
};
Input& InputCollection::operator[](unsigned int idx)  {
	return this->get(idx);
};
void InputCollection::add(Output &output){
	Input * input = registerNewInput();
	input->connect(output);
};
void InputCollection::add(float &value){
	Input * input = registerNewInput();
	(*input) = value;
};
void InputCollection::add(float value){
	Input * input = registerNewInput();
	(*input) = value;
};
void InputCollection::clear(){
	while(collection.size()){
		collection[0]->disconnect();
		delete collection[0];
		collection.removeAt(0);
	}
};
Input * InputCollection::registerNewInput(){
	Input * input = new Input();
	node->registerInput(*input);
	collection.add(input);
	return input;
}
