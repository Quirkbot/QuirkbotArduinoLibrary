#include <StandardCplusplus.h>
#include <QuirkBug.h>

#include <nodes/Time.h>
#include <nodes/Sine.h>
#include <nodes/Logger.h>

Time time;
Sine sine;
Logger logger;

void setup() {	
	sine.source = time.seconds;
	logger.source = sine.result;
}

void loop() {
	delay(1000);
}
