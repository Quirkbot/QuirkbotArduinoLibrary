#include <QuirkBug.h>

#include <SonarSensor.h>
#include <AnalogSensor.h>
#include <Logger.h>


SonarSensor sonar;
AnalogSensor light;

SerialPrint print;

void setup() {	

	light.pin = A0;
	//light.min = 0.05;
	//light.max = 0.2;
	//light.start = 1;
	//light.end = 0;


	sonar.pin = 7;
	sonar.min = 0.01;
	sonar.max = 0.12;
	sonar.start = 440;
	sonar.end = 1000;
		
	print(sonar.raw, sonar.value);

}


void loop(){}