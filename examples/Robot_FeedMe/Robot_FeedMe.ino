#include "QuirkBug.h"

Servo servo;
Sonar sonar;

Converter converter;
Sequence sequence;

Monitor monitor;

void setup(){
	sonar.pin = 7;

	converter.set(0.2, 0.5, 1, 0);
	converter.connect(sonar);

	sequence.add(0.7);
	sequence.add(0.35);
	sequence.add(0.35);
	sequence.add(0.35);
	sequence.add(0.35);
	sequence.add(0.35);
	sequence.add(0.35);
	sequence.add(0.7);
	sequence.add(0.35);
	sequence.add(0.7);
	sequence.add(0.35);
	sequence.add(0.7);
	sequence.add(0.35);
	sequence.add(0.7);
	sequence.duration = 3;

	sequence.trigger(converter);

	servo.pin = 3;

	servo.connect(sequence);

	monitor.add(sonar);
	monitor.add(converter);
	monitor.add(sequence);
}