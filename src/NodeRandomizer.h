#ifndef NodeRandomizer_h_
#define NodeRandomizer_h_

#include "CommonNodeIncludes.h"

class Randomizer :
public Node,
public HasInterval
{
	public:

	Randomizer();
	~Randomizer();

	Input min;
	Input max;

	Output out;

	void onInterval();
};
#endif
