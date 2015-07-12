#include "List.h"

List::List():
HasInputCollection
	(this),
HasIn
	(this),
HasOut
	(this){
	selected = NULL;	
}
List::~List(){}
void List::onItemsUpdated(){
	refreshSelected();
}
void List::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		refreshSelected();		
	}
	else if(&internalInput == selected){
		out.set(selected->get());
	}
}