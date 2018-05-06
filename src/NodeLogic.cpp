#include "NodeLogic.h"

Logic::Logic(){
	registerInput(operation);
	registerInputCollection(items);
	registerInput(close);
	registerInput(open);

	operation = LOGIC_AND;
	close = 0.0;
	open = 1.0;
}
Logic::~Logic(){}
void Logic::onInternalInputChange(BaseInput&){
	bool result;

	if(operation.get() == LOGIC_AND) {
		result = true;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if(items.collection[i]->get() == 0){
				result = false;
				break;
			}
		}
	}
	else if(operation.get() == LOGIC_OR) {
		result = false;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if(items.collection[i]->get() != 0){
				result = true;
				break;
			}
		}
	}
	else if(operation.get() == LOGIC_XOR) {
		result = false;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if(items.collection[i]->get() != 0){
				result = !result;
			}
		}
	}

	out.set(result ? open.get() : close.get());
}
