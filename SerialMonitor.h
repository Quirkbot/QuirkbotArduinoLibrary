#ifndef SerialMonitor_h_
#define SerialMonitor_h_

#include "CommonNodeIncludes.h"

class SerialMonitor:
public Node,
public HasInterval,
public HasInputCollection{
	public:

	SerialMonitor();
	~SerialMonitor();

	void onInterval();
};
#endif