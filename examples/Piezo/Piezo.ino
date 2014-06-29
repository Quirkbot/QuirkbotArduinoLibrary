#include <QuirkBug.h>

#include <SonarSensor.h>
#include <Oscillator.h>
#include <Buzzer.h>
#include <Logger.h>


SonarSensor sonar;
Oscillator osc;
Buzzer buzzer;

SerialPrint print;

void setup() {	


	sonar.pin = 7;
	sonar.min = 0.01;
	sonar.max = 0.12;
	sonar.begin = 0.1;
	sonar.end = 1;

	osc.type = OSC_SQUARE;
	osc.duration.connect(sonar.output);
	
	buzzer.input.connect(osc.output);


	print(sonar.raw, sonar.output, osc.output);
}


void loop(){

		buzzer.pin = 4;

		delay(1000);
}