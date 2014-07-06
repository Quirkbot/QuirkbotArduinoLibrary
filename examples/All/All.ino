#include "QuirkBug.h"

Sonar sonar;
LightSensor light;

Servo servo;

Led led1;
Led led2;

Buzzer buzzer;

Wave wave;

Monitor monitor;

void setup() {
	light.pin = A0;
	servo.pin = 3;
	buzzer.pin = 4;
	led1.pin = 5;
	led2.pin = 6;
	sonar.pin = 7;
	
	wave.duration = 1;
	wave.type = OSC_RAMP_UP;
	
	servo.connect(sonar);	
	led1.connect(wave);	
	buzzer.connect(light);

	led2.connect(light);


	sonar.min = 0.03;
	sonar.max = 0.15;


	monitor(sonar.raw, sonar.value);

}