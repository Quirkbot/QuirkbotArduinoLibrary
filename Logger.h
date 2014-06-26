#ifndef Logger_h_
#define Logger_h_

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Logger:
public Node,
public InputStream<float>,
public Contains5Inputs<float, char*, float, float, float>{
	public:
	
	Logger();

	Input<float> base;
	Input<char*> label;
	Input<float> throttle;

	Input<float> showLabel;
	Input<float> showTimestamp;

	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	void init(Stream &stream);
	Stream * streamPtr;

	float lastPrintMillis;
};

typedef Logger SerialPrint;
#endif
