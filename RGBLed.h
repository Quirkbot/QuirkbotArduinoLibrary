#ifndef RGBLed_h_
#define RGBLed_h_

#include "CommonNodeIncludes.h"

class RGBLed :
public Node,
public HasIn<float>{
	public:
	
	RGBLed();

	Input<int> pinR;
	Input<int> pinG;
	Input<int> pinB;
	Input<float> hue;
	Input<float> saturation;

	protected:
	float r,g,b;

	void onInternalInputChange(BaseInput &internalInput);
	void calculateRGB(float h, float s, float l);
	void writePins();
};
#endif