#include <QuirkBug.h>

// Create the nodes
/*Randomizer position1;
Randomizer position2;
Wave turn;

Gate gate;
Sonar sonar;

Servo servo;
Led led;
Sequence sequence;
List list;
Monitor monitor;
*/
Monitor monitor;
Sonar sonar;
void setup() {
	/*position1.set(0.3, 0.5);
	position1.interval = 6;

	position2.set(0.5, 0.8);
	position2.interval = 6;

	turn.set(position1, position2);
	turn.duration = 3;

	gate.connect(turn);

	servo.pin = 3;
	servo.connect(turn);

	led.pin = 5;
	led.light.connect(turn);

	sonar.pin = 7;
	
	monitor.add(turn);
	monitor.add(gate);
	monitor.add(sonar);*/
	sonar.pin = 7;
	monitor.add(sonar);
}