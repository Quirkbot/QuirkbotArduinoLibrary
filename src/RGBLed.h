#ifndef RGBLed_h_
#define RGBLed_h_

#include "CommonNodeIncludes.h"

class RGBLed :
public Node,
public HasIn{
	public:

	RGBLed();
	~RGBLed();

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