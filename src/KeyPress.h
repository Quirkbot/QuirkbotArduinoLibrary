#ifndef KeyPress_h_
#define KeyPress_h_

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
