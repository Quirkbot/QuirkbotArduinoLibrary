#include "Quirkbot.h"

Servo servo;
Wave wave;

void setup() {
	wave.duration = 3;
	servo.pin = 3;
	servo.connect(wave);
}