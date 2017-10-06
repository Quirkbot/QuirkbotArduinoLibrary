#ifndef NodeKeyPress_h_
#define NodeKeyPress_h_

#include "CommonNodeIncludes.h"

class KeyPress :
public Node,
public HasTrigger
{
	public:

	KeyPress();
	~KeyPress();

	Input key;

	protected:

	void onInternalInputChange(BaseInput &internalInput);

	int currentKey;
	bool pressed;
};
#endif
