#ifndef RGBLed_h_
#define RGBLed_h_

#include "CommonNodeIncludes.h"

class RGBLed :
public Node,
public HasIn<float>{
	public:
	
	RGBLed();

	InputFloat pinR;
	InputFloat pinG;
	InputFloat pinB;
	InputFloat hue;
	InputFloat saturation;

	protected:
	float r,g,b;

	void onInternalInputChange(BaseInput &internalInput);
	void calculateRGB(float h, float s, float l);
	void writePins();
};
#endif