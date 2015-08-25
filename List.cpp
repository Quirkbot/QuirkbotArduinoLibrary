#include "List.h"

List::List():
HasIn
	(this),
HasOut
	(this){
	registerInputCollection(items);
	selected = NULL;
}
List::~List(){}
void List::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		refreshSelected();
	}
	else if(&internalInput == selected){
		out.set(selected->get());
	}
}
void List::refreshSelected(){
	if(items.collection.size()){
		int i = floor(in.get() * items.collection.size());
		if(i < 0 ) i  = 0;
		if(i >= items.collection.size()) i = items.collection.size() - 1;
		if(items.collection[i] != selected){
			selected = items.collection[i];
			out.set(selected->get());
		}
	}
	else{
		selected = NULL;
		out.set(0);
	}
}
