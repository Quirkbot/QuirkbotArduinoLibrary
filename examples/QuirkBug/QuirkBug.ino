#include <StandardCplusplus.h>
#include <QuirkBug.h>

#include <Time.h>
#include <Sine.h>
#include <Sensor.h>
#include <Logger.h>


Time time;
Sine sine;

Sensor sensor;
Logger logger;

void setup() {	

	sensor.pin = A0;
	sensor.sensibility = 0.1;

	logger.source = sensor.value;
	
	//sine.source = time.seconds;
	//logger.source = sine.result;
}

void loop() {
	delay(1000);
}