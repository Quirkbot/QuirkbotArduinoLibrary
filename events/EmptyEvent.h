#ifndef EmptyEvent_h_
#define EmptyEvent_h_

#include <vector>

typedef void (*EmptyEventHandler)();

class EmptyEvent {
	public:
	void add(EmptyEventHandler handler);
	void remove(EmptyEventHandler handler);
	void dispatch();
	int handlerPosition(EmptyEventHandler handler);
	
	private:
	std::vector<EmptyEventHandler> handlers;
};

#endif
