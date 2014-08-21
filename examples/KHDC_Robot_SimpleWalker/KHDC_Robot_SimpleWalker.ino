#include "Quirkbot.h"

ServoMotor servo;
Wave wave;

void start() {
	wave.duration = 3;
	servo.pin = 3;
	servo.connect(wave);
}