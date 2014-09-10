#ifndef RGBLed_h_
#define RGBLed_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Streams.h"


class RGBLed :
public Node,
public InputStream<float>{
	public:
	
	RGBLed():
	InputStream<float>
		(luminosity){
		registerInput(pinR);
		registerInput(pinG);
		registerInput(pinB);
		registerInput(hue);
		registerInput(saturation);
		registerInput(luminosity);

		pinR = -1;
		pinG = -1;
		pinB = -1;

		luminosity = 0;
		saturation = 1;
		hue = 1;
	};

	Input<int> pinR;
	Input<int> pinG;
	Input<int> pinB;
	Input<float> hue;
	Input<float> saturation;	
	Input<float> luminosity;

	protected:
	float r,g,b;

	void onInternalInputChange(BaseInput &input);
	void calculateRGB(float h, float s, float l);
	void writePins();
};
void RGBLed::onInternalInputChange(BaseInput &input){
	if(&input == &pinR) pinMode(pinR.get(), OUTPUT);
	else if(&input == &pinG) pinMode(pinG.get(), OUTPUT);
	else if(&input == &pinB) pinMode(pinB.get(), OUTPUT);
	else if(&input == &hue || &input == &saturation || &input == &luminosity){
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
		Serial.println(v);
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
	analogWrite(pinR.get(), pow(r * luminosity.get(), 2.5) * 255.0);
	analogWrite(pinG.get(), pow(g * luminosity.get(), 2.5) * 255.0);
	analogWrite(pinB.get(), pow(b * luminosity.get(), 2.5) * 255.0);

}
#endif
