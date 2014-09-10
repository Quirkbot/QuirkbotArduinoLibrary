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
		(index, value){
		registerInput(index);
		selected = NULL;

		index = 0;
		
	};

	Input<float> index;
	Output<float> value;
	
	protected:

	void onInternalInputChange(BaseInput &input);
	void onItemsUpdated();

	private:

	void refreshSelected(){
		if(inputCollection.size()){
			int i = floor(index.get() * inputCollection.size()); 
			if(i < 0 ) i  = 0;
			if(i >= inputCollection.size()) i = inputCollection.size() - 1;
			if(inputCollection[i] != selected){
				selected = inputCollection[i];
				value.set(selected->get());
			}
		}	
		else{
			selected = NULL;
			value.set(0);
		}
	}

	Input<float> * selected;
};
void List::onItemsUpdated(){
	refreshSelected();
};
void List::onInternalInputChange(BaseInput &input){
	if(&input == &index){
		refreshSelected();		
	}
	else if(&input == selected){
		value.set(selected->get());
	}
};

#endif
