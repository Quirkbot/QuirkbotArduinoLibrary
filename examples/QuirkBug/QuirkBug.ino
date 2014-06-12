#include <QuirkBug.h>

#include <Time.h>
#include <Sine.h>
#include <Sensor.h>
#include <Logger.h>
#include <Led.h>

Time time;
Sine sine;
Led led;
Sensor sensor;
Logger logger;

void setup() {	
	sensor.pin = A0;

	sine.source = time.seconds;


	led.pin = 11;
	//led.brighteness = sine.result;
	led.brighteness = sensor.value;
	//led.on();

	//logger.source = led.value;
}

void loop() {
	//led.on();
	delay(1000);
	//led.off();
	delay(1000);
}