#ifndef NodeRGBLed_h_
#define NodeRGBLed_h_

#include "CommonNodeIncludes.h"

class RGBLed :
public Node
{
	public:

	RGBLed();
	~RGBLed();

	Input in;
	Input pinR;
	Input pinG;
	Input pinB;
	Input hue;
	Input saturation;

	protected:
	float r,g,b;

	void onInternalInputChange(BaseInput &internalInput);
	void calculateRGB(float h, float s, float l);
	void writePins();
};
#endif
