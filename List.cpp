#include "List.h"

List::List():
HasInputCollection<float>
	(this),
HasIn<float>
	(this),
HasOut<float>
	(this){
	selected = NULL;	
}
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