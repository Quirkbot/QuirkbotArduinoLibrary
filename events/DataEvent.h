#ifndef DataEvent_h_
#define DataEvent_h_

#include <vector>

typedef void (*DataEventHandler)(void* data);

class DataEvent {
	public:
	void add(DataEventHandler handler);
	void remove(DataEventHandler handler);
	void dispatch(void* value);
	int handlerPosition(DataEventHandler handler);
	
	private:
	std::vector<DataEventHandler> handlers;
};

#endif
