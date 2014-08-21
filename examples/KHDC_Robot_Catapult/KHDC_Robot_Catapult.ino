#include "Quirkbot.h"

ServoMotor servo;
Sonar sonar;
Converter converter;
Sequence sequence;
SerialMonitor monitor;

Wave wave;

void start(){
	sequence.add(0.15);
	sequence.add(0.0);
	sequence.add(1.0);
	sequence.add(0.15);
	sequence.duration = 3;

	servo.pin = 3;
	servo.value = 0.15;
	servo.connect(sequence);

	sonar.pin = 7;

	converter.set(0.5, 1.0, 1, 0);
	converter.connect(sonar);

	sequence.trigger(converter);

	monitor.add(sonar);
	monitor.add(converter);
}