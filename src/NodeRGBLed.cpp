#include "NodeRGBLed.h"

RGBLed::RGBLed(){
	registerInput(in);
	registerInput(pinR);
	registerInput(pinG);
	registerInput(pinB);
	registerInput(hue);
	registerInput(saturation);

	in = 0.0;
	pinR = NO_LOCATION;
	pinG = NO_LOCATION;
	pinB = NO_LOCATION;
	saturation = 1;
	hue = 1;
}
RGBLed::~RGBLed(){}
void RGBLed::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &pinR) pinMode(pinR.get(), OUTPUT);
	else if(&internalInput == &pinG) pinMode(pinG.get(), OUTPUT);
	else if(&internalInput == &pinB) pinMode(pinB.get(), OUTPUT);
	else if(&internalInput == &hue || &internalInput == &saturation || &internalInput == &in){
		calculateRGB(hue.get(), saturation.get(), 0.5);
		writePins();
	};
};
void RGBLed::calculateRGB(float h, float s, float l) {
	float v;
	v = (l <= 0.5) ? (l * (1.0 + s)) : (l + s - l * s);

	if (v > 0) {
		float m;
		float sv;
		int sextant;
		float fract, vsf, mid1, mid2;

		m = l + l - v;
		sv = (v - m ) / v;
		h *= 6.0;
		sextant = (int)h;
		fract = h - sextant;
		vsf = v * sv * fract;
		mid1 = m + vsf;
		mid2 = v - vsf;

		switch (sextant){
			case 0:
				r = v;
				g = mid1;
				b = m;
				break;
			case 1:
				r = mid2;
				g = v;
				b = m;
				break;
			case 2:
				r = m;
				g = v;
				b = mid1;
				break;
			case 3:
				r = m;
				g = mid2;
				b = v;
				break;
			case 4:
				r = mid1;
				g = m;
				b = v;
				break;
			case 5:
				r = v;
				g = m;
				b = mid2;
				break;
		}
	}
	else{
		r = l;
		g = l;
		b = l;
	}
}
void RGBLed::writePins(){
	analogWrite(pinR.get(), pow(r * in.get(), 2.5) * 255.0);
	analogWrite(pinG.get(), pow(g * in.get(), 2.5) * 255.0);
	analogWrite(pinB.get(), pow(b * in.get(), 2.5) * 255.0);
}
