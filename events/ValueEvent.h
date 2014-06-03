#ifndef ValueEvent_h_
#define ValueEvent_h_

#include <vector>

typedef void (*ValueEventHandler)(float value);

class ValueEvent {
	public:
	void add(ValueEventHandler handler);
	void remove(ValueEventHandler handler);
	void dispatch(float value);
	int handlerPosition(ValueEventHandler handler);
	
	private:
	std::vector<ValueEventHandler> handlers;
};

#endif
