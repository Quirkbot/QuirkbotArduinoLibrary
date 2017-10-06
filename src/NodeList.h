#ifndef NodeList_h_
#define NodeList_h_

#include "CommonNodeIncludes.h"

class List:
public Node,
public HasIn,
public HasOut
{
	public:

	List();
	~List();

	InputCollection items;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	void refreshSelected();

	Input * selected;
};
#endif
