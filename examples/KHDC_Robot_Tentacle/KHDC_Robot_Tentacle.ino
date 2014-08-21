#include <Quirkbot.h>

Sonar sonar;
Converter converter;
ServoMotor servo;

SerialMonitor monitor;

void start() {        
	sonar.pin = 7;

	converter.set(0.0, 0.5, 0, 0.7);
	converter.connect(sonar);

	servo.pin = 3;
	servo.connect(converter);

	monitor.add(sonar);
	monitor.add(converter);
}