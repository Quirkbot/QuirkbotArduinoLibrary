#include <QuirkBug.h>

AnalogSensor sensor;
Sequence sequence;
Led led;

Monitor monitor;

void setup() {
	sensor.pin = A0;
	sensor.min = 0.3;
	sensor.max = 0.3;

	sequence.add(0);
	sequence.add(1);
	sequence.add(1);
	sequence.add(0);
	sequence.add(1);
	sequence.add(0);
	sequence.duration = 500;

	sequence.trigger.connect(sensor);

	led.pin = 5;
	led.connect(sequence);	
	
	monitor.add(sensor.raw);
	monitor.add(sensor);
}