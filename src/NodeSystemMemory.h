#ifndef NodeSystemMemory_h_
#define NodeSystemMemory_h_

#include "CommonNodeIncludes.h"

class SystemMemory :
public Node,
public HasInterval
{
	public:

	SystemMemory();
	~SystemMemory();

	void onInterval();

	Output out;

	private:

	static int getFreeRam();

};
#endif
