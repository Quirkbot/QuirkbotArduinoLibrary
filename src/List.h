#ifndef List_h_
#define List_h_

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
