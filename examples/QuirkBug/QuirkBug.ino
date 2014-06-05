#include <TimerOne.h>
#include <StandardCplusplus.h>
#include <QuirkBug.h>

#include <nodes/Time.h>
#include <nodes/Logger.h>


Time time;
Logger logger;


void setup() {
	Serial.begin(9600);
	Timer1.initialize();
	Timer1.attachInterrupt( Bot::update,  BOT_TIME_INCREMENT_MICROS);

	
	logger.source = time.seconds;
	logger.interval = 100;
}


void loop() {

}
