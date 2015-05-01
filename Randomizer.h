#ifndef Randomizer_h_
#define Randomizer_h_

#include "CommonNodeIncludes.h"

class Randomizer :
public Node,
public HasInterval,
public HasOut
{
	public:

	Randomizer();

	void onInterval();
};
#endif