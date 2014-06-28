#include <QuirkBug.h>

#include <SonarSensor.h>
#include <Buzzer.h>
#include <Logger.h>


SonarSensor sonar;
Buzzer buzzer;

SerialPrint print;

void setup() {	


	sonar.pin = 7;
	sonar.min = 0.01;
	sonar.max = 0.12;
	
	buzzer.pin = 9;
	buzzer.volume = sonar.value;
	buzzer.stop();

	print(sonar.raw, sonar.value);

}


void loop(){}