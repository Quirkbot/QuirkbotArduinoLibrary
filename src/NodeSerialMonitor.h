#ifndef NodeSerialMonitor_h_
#define NodeSerialMonitor_h_

#include "CommonNodeIncludes.h"

class SerialMonitor:
public Node,
public HasInterval{
	public:

	SerialMonitor();
	~SerialMonitor();

	InputCollection items;

	void onInterval();
};
#endif
