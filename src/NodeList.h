#ifndef NodeList_h_
#define NodeList_h_

#include "CommonNodeIncludes.h"

class List:
public Node
{
	public:

	List();
	~List();

	Input in;
	InputCollection items;

	Output out;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	private:

	void refreshSelected();

	Input * selected;
};
#endif
