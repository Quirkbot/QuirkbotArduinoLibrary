#ifndef Logger_h_
#define Logger_h_

#include "Bot.h"
#include "BaseNode.h"

#include "Arduino.h"

class Logger : public BaseNode{
	public:
	
	Logger();
	Logger(Stream &stream);
	~Logger(){};

	Parameter input;
	Parameter interval;

	protected:

	void onParameterUpdated(Parameter& parameter);

	private:

	void init(Stream &stream);
	Stream * streamPtr;

	float lastPrintMillis;
};

#endif
