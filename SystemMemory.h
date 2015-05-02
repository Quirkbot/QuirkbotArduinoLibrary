#ifndef SystemMemory_h_
#define SystemMemory_h_

#include "CommonNodeIncludes.h"

class SystemMemory :
public Node,
public HasInterval,
public HasOut
{
	public:

	SystemMemory();
	~SystemMemory();

	void onInterval();

	private:

	static int getFreeRam();

};
#endif