#ifndef SimpleEvent_h_
#define SimpleEvent_h_

#include <vector>

typedef void (*SimpleEventHandler)();

class SimpleEvent {
	public:
	void add(SimpleEventHandler handler);
	void remove(SimpleEventHandler handler);
	void dispatch();
	int handlerPosition(SimpleEventHandler handler);
	
	private:
	std::vector<SimpleEventHandler> handlers;
};

#endif
