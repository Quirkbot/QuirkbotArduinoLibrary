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
public Contains6Inputs<float, float, float, float, float, float>{
	public:
	
	Logger();

	Input<float> a;
	Input<float> b;
	Input<float> c;
	Input<float> d;
	Input<float> e;
	Input<float> throttle;


	protected:

	void onInternalInputChange(BaseInput &input);

	private:

	float lastPrintMillis;
};

typedef Logger SerialPrint;
typedef Logger Monitor;
#endif
