#ifndef Easing_h_
#define Easing_h_

#include "Arduino.h"

#define EASING_LINEAR 0
#define EASING_SINE_IN 1
#define EASING_SINE_OUT 2
#define EASING_SINE_IN_OUT 3
#define EASING_QUAD_IN 4
#define EASING_QUAD_OUT 5
#define EASING_QUAD_IN_OUT 6
#define EASING_CUBIC_IN 7
#define EASING_CUBIC_OUT 8
#define EASING_CUBIC_IN_OUT 9
#define EASING_QUART_IN 10
#define EASING_QUART_OUT 11
#define EASING_QUART_IN_OUT 12
#define EASING_QUINT_IN 13
#define EASING_QUINT_OUT 14
#define EASING_QUINT_IN_OUT 15
#define EASING_EXPO_IN 16
#define EASING_EXPO_OUT 17
#define EASING_EXPO_IN_OUT 18
#define EASING_CIRC_IN 19
#define EASING_CIRC_OUT 20
#define EASING_CIRC_IN_OUT 21
#define EASING_BACK_IN 22
#define EASING_BACK_OUT 23
#define EASING_BACK_IN_OUT 24
#define EASING_ELASTIC_IN 25
#define EASING_ELASTIC_OUT 26
#define EASING_ELASTIC_IN_OUT 27
#define EASING_BOUNCE_IN 28
#define EASING_BOUNCE_OUT 29
#define EASING_BOUNCE_IN_OUT 30

namespace Easing {
	float function(uint8_t type, float t, float b, float c, float d);

	float linear(float t, float b, float c, float d);

	float sineIn(float t, float b, float c, float d);
	float sineOut(float t, float b, float c, float d);
	float sineInOut(float t, float b, float c, float d);

	float quadIn(float t, float b, float c, float d);
	float quadOut(float t, float b, float c, float d);
	float quadInOut(float t, float b, float c, float d);

	float cubicIn(float t, float b, float c, float d);
	float cubicOut(float t, float b, float c, float d);
	float cubicInOut(float t, float b, float c, float d);

	float quartIn(float t, float b, float c, float d);
	float quartOut(float t, float b, float c, float d);
	float quartInOut(float t, float b, float c, float d);

	float quintIn(float t, float b, float c, float d);
	float quintOut(float t, float b, float c, float d);
	float quintInOut(float t, float b, float c, float d);

	float expoIn(float t, float b, float c, float d);
	float expoOut(float t, float b, float c, float d);
	float expoInOut(float t, float b, float c, float d);

	float circIn(float t, float b, float c, float d);
	float circOut(float t, float b, float c, float d);
	float circInOut(float t, float b, float c, float d);

	float backIn(float t, float b, float c, float d);
	float backOut(float t, float b, float c, float d);
	float backInOut(float t, float b, float c, float d);

	float elasticIn(float t, float b, float c, float d);
	float elasticOut(float t, float b, float c, float d);
	float elasticInOut(float t, float b, float c, float d);

	float bounceIn(float t, float b, float c, float d);
	float bounceOut(float t, float b, float c, float d);
	float bounceInOut(float t, float b, float c, float d);
}

#endif
