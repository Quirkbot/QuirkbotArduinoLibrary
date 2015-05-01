#ifndef List_h_
#define List_h_

#include "CommonNodeIncludes.h"

class List:
public Node,
public HasInputCollection<float>,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	List();
	
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

	InputFloat * selected;
};
#endif