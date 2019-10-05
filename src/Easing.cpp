/*
*
* TERMS OF USE - EASING EQUATIONS
*
* Open source under the BSD License.
*
* Copyright © 2001 Robert Penner
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of
* conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list
* of conditions and the following disclaimer in the documentation and/or other materials
* provided with the distribution.
*
* Neither the name of the author nor the names of contributors may be used to endorse
* or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
*  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#include "Easing.h"

float Easing::function(uint8_t type, float t, float b, float c, float d) {
	switch (type) {
		case EASING_SINE_IN:
			return Easing::sineIn(t, b, c, d);
		case EASING_SINE_OUT:
			return Easing::sineOut(t, b, c, d);
		case EASING_SINE_IN_OUT:
			return Easing::sineInOut(t, b, c, d);
		case EASING_QUAD_IN:
			return Easing::quadIn(t, b, c, d);
		case EASING_QUAD_OUT:
			return Easing::quadOut(t, b, c, d);
		case EASING_QUAD_IN_OUT:
			return Easing::quadInOut(t, b, c, d);
		case EASING_CUBIC_IN:
			return Easing::cubicIn(t, b, c, d);
		case EASING_CUBIC_OUT:
			return Easing::cubicOut(t, b, c, d);
		case EASING_CUBIC_IN_OUT:
			return Easing::cubicInOut(t, b, c, d);
		case EASING_QUART_IN:
			return Easing::quartIn(t, b, c, d);
		case EASING_QUART_OUT:
			return Easing::quartOut(t, b, c, d);
		case EASING_QUART_IN_OUT:
			return Easing::quartInOut(t, b, c, d);
		case EASING_QUINT_IN:
			return Easing::quintIn(t, b, c, d);
		case EASING_QUINT_OUT:
			return Easing::quintOut(t, b, c, d);
		case EASING_QUINT_IN_OUT:
			return Easing::quintInOut(t, b, c, d);
		case EASING_EXPO_IN:
			return Easing::expoIn(t, b, c, d);
		case EASING_EXPO_OUT:
			return Easing::expoOut(t, b, c, d);
		case EASING_EXPO_IN_OUT:
			return Easing::expoInOut(t, b, c, d);
		case EASING_CIRC_IN:
			return Easing::circIn(t, b, c, d);
		case EASING_CIRC_OUT:
			return Easing::circOut(t, b, c, d);
		case EASING_CIRC_IN_OUT:
			return Easing::circInOut(t, b, c, d);
		case EASING_BACK_IN:
			return Easing::backIn(t, b, c, d);
		case EASING_BACK_OUT:
			return Easing::backOut(t, b, c, d);
		case EASING_BACK_IN_OUT:
			return Easing::backInOut(t, b, c, d);
		case EASING_ELASTIC_IN:
			return Easing::elasticIn(t, b, c, d);
		case EASING_ELASTIC_OUT:
			return Easing::elasticOut(t, b, c, d);
		case EASING_ELASTIC_IN_OUT:
			return Easing::elasticInOut(t, b, c, d);
		case EASING_BOUNCE_IN:
			return Easing::bounceIn(t, b, c, d);
		case EASING_BOUNCE_OUT:
			return Easing::bounceOut(t, b, c, d);
		case EASING_BOUNCE_IN_OUT:
			return Easing::bounceInOut(t, b, c, d);
		case EASING_LINEAR:
		default:
			return Easing::linear(t, b, c, d);
	}
}

float Easing::linear(float t, float b, float c, float d){
	return c*t/d + b;
}

float Easing::sineIn(float t, float b, float c, float d){
	return -c * cos(t/d * (PI/2)) + c + b;
}
float Easing::sineOut(float t, float b, float c, float d){
	return c * sin(t/d * (PI/2)) + b;
}
float Easing::sineInOut(float t, float b, float c, float d){
	return -c/2 * (cos(PI*t/d) - 1) + b;
}

float Easing::quadIn(float t, float b, float c, float d){
	return c*(t/=d)*t + b;
}
float Easing::quadOut(float t, float b, float c, float d){
	return -c *(t/=d)*(t-2) + b;
}
float Easing::quadInOut(float t, float b, float c, float d){
	if ((t /= d / 2) < 1) return c / 2 * t * t + b;
	return -c / 2 * ((--t) * (t - 2) - 1) + b;
}

float Easing::cubicIn(float t, float b, float c, float d){
	return c*(t/=d)*t*t + b;
}
float Easing::cubicOut(float t, float b, float c, float d){
	return c*((t=t/d-1)*t*t + 1) + b;
}
float Easing::cubicInOut(float t, float b, float c, float d){
	if ((t/=d/2) < 1) return c/2*t*t*t + b;
	return c/2*((t-=2)*t*t + 2) + b;
}

float Easing::quartIn(float t, float b, float c, float d){
	return c*(t/=d)*t*t*t + b;
}
float Easing::quartOut(float t, float b, float c, float d){
	return -c * ((t=t/d-1)*t*t*t - 1) + b;
}
float Easing::quartInOut(float t, float b, float c, float d){
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
	return -c/2 * ((t-=2)*t*t*t - 2) + b;
}

float Easing::quintIn(float t, float b, float c, float d){
	return c*(t/=d)*t*t*t*t + b;
}
float Easing::quintOut(float t, float b, float c, float d){
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}
float Easing::quintInOut(float t, float b, float c, float d){
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}

float Easing::expoIn(float t, float b, float c, float d){
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}
float Easing::expoOut(float t, float b, float c, float d){
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}
float Easing::expoInOut(float t, float b, float c, float d){
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

float Easing::circIn(float t, float b, float c, float d){
	return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}
float Easing::circOut(float t, float b, float c, float d){
	return c * sqrt(1 - (t=t/d-1)*t) + b;
}
float Easing::circInOut(float t, float b, float c, float d){
	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
}

float Easing::backIn(float t, float b, float c, float d){
	float s = 1.70158f;
	float postFix = t/=d;
	return c*(postFix)*t*((s+1)*t - s) + b;
}
float Easing::backOut(float t, float b, float c, float d){
	float s = 1.70158f;
	return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}
float Easing::backInOut(float t, float b, float c, float d){
	float s = 1.70158f;
	if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
	float postFix = t-=2;
	return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}

float Easing::elasticIn(float t, float b, float c, float d){
	if (t==0) return b;
	if ((t/=d)==1) return b+c;
	float p=d*.3f;
	float a=c;
	float s=p/4;
	float postFix=a*pow(2,10*(t-=1));
	return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}
float Easing::elasticOut(float t, float b, float c, float d){
	if (t==0) return b;
	if ((t/=d)==1) return b+c;
	float p=d*.3f;
	float a=c;
	float s=p/4;
	return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}
float Easing::elasticInOut(float t, float b, float c, float d){
	if (t==0) return b;  if ((t/=d/2)==2) return b+c;
	float p=d*(.3f*1.5f);
	float a=c;
	float s=p/4;

	if (t < 1) {
		float postFix=a*pow(2,10*(t-=1));
		return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
	}
	float postFix=a*pow(2,-10*(t-=1));
	return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}

float Easing::bounceIn(float t, float b, float c, float d){
	return c - Easing::bounceOut(d-t, 0, c, d) + b;
}
float Easing::bounceOut(float t, float b, float c, float d){
	if ((t/=d) < (1/2.75f)) {
		return c*(7.5625f*t*t) + b;
	} else if (t < (2/2.75f)) {
		float postFix = t-=(1.5f/2.75f);
		return c*(7.5625f*(postFix)*t + .75f) + b;
	} else if (t < (2.5/2.75)) {
			float postFix = t-=(2.25f/2.75f);
		return c*(7.5625f*(postFix)*t + .9375f) + b;
	} else {
		float postFix = t-=(2.625f/2.75f);
		return c*(7.5625f*(postFix)*t + .984375f) + b;
	}
}
float Easing::bounceInOut(float t, float b, float c, float d){
	if (t < d/2) return Easing::bounceIn(t*2, 0, c, d) * .5f + b;
	else return Easing::bounceOut(t*2-d, 0, c, d) * .5f + c*.5f + b;
}
