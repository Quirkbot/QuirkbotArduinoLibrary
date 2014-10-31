#include "Quirkbot.h"

Wave wave;
Converter converter;

Sonar sonar;
AnalogSensor analogSensor;
ServoMotor servo;
Led led;

SerialMonitor monitor;

void start(){
	wave.duration = 5;

	converter.in.connect(wave.out);
	converter.inMin = 0;
	converter.inMax = 1;
	converter.outMin = 0.47;
	converter.outMax = 0.53;

	servo.pin = 8;
	servo.in.connect(converter.out);

	led.pin = 6;
	led.in.connect(wave.out);

	monitor[0].connect(wave.out);
	monitor[1].connect(converter.out);
}