#include <QuirkBug.h>

//#include <Time.h>
//#include <Sine.h>
#include <Sensor.h>
#include <Logger.h>
#include <Led.h>


Led led;
Sensor sensor;
Logger logger;

void setup() {	
	sensor.pin = A0;

	led.pin = 11;
	led.brighteness = sensor.value;

	logger.source = sensor.value;
}

void loop() {

}