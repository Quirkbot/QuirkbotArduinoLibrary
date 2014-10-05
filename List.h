#ifndef List_h_
#define List_h_

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "HasIn.h"
#include "HasOut.h"
#include "HasInputCollection.h"

class List:
public Node,
public HasInputCollection<float>,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	List():
	HasInputCollection<float>
		(this),
	HasIn<float>
		(this),
	HasOut<float>
		(this){
		selected = NULL;	
	};
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);
	void onItemsUpdated();

	private:

	void refreshSelected(){
		if(items.size()){
			int i = floor(in.get() * items.size()); 
			if(i < 0 ) i  = 0;
			if(i >= items.size()) i = items.size() - 1;
			if(items[i] != selected){
				selected = items[i];
				out.set(selected->get());
			}
		}	
		else{
			selected = NULL;
			out.set(0);
		}
	}

	Input<float> * selected;
};
void List::onItemsUpdated(){
	refreshSelected();
};
void List::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		refreshSelected();		
	}
	else if(&internalInput == selected){
		out.set(selected->get());
	}
};

#endif
