#ifndef SystemMemory_h_
#define SystemMemory_h_

#include "CommonNodeIncludes.h"

class SystemMemory :
public Node,
public HasInterval,
public HasOut<float>
{
	public:

	SystemMemory();

	void onInterval();

	private:

	static int getFreeRam();

};
#endif