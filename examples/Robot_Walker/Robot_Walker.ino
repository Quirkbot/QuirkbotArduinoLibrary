#include "QuirkBug.h"

Servo servo;
Wave wave;
Converter converter;

void setup() {
	wave.duration = 1;
	wave.type = WAVE_RAMP_DOWN;

	converter.set(0, 1, 0, 0.4);
	converter.connect(wave);

	servo.pin = 3;
	servo.connect(converter);
}