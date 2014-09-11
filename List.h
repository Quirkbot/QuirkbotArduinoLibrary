#ifndef List_h_
#define List_h_

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "Streams.h"
#include "HasInputCollection.h"

class List:
public Node,
public HasInputCollection<float>,
public InputOutputStream<float>
{
	public:
	
	List():
	HasInputCollection<float>
		(this),
	InputOutputStream<float>
		(this){
		selected = NULL;	
	};
	
	protected:

	void onInternalInputChange(BaseInput &internalInput);
	void onItemsUpdated();

	private:

	void refreshSelected(){
		if(inputCollection.size()){
			int i = floor(in.get() * inputCollection.size()); 
			if(i < 0 ) i  = 0;
			if(i >= inputCollection.size()) i = inputCollection.size() - 1;
			if(inputCollection[i] != selected){
				selected = inputCollection[i];
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
