#ifndef Logger_h_
#define Logger_h_

#include <map>

#include "Bot.h"
#include "Node.h"
#include "Input.h"


#include "Arduino.h"

class Logger : public Node{
	public:
	
	Logger();
	Logger(Stream &stream);

	Input<float> source;
	Input<float> interval;

	protected:

	void onInternalInputChange(BaseInput &input);
	void onSourceChange();

	private:

	void init(Stream &stream);
	Stream * streamPtr;

	float lastPrintMillis;
};

#endif
