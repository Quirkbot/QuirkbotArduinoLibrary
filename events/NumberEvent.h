#ifndef NumberEvent_h_
#define NumberEvent_h_

#include <vector>

typedef void (*NumberEventHandler)(float);

class NumberEvent {
	public:
	void add(NumberEventHandler handler);
	void remove(NumberEventHandler handler);
	void dispatch(float value);
	int handlerPosition(NumberEventHandler handler);
	
	private:
	std::vector<NumberEventHandler> handlers;
};

#endif
