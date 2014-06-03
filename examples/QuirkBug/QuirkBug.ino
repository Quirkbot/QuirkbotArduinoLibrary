#include <TimerOne.h>
#include <StandardCplusplus.h>
#include <QuirkBug.h>

#include <nodes/Micros.h>
#include <nodes/Multiplication.h>
#include <nodes/Logger.h>


Micros time;
Multiplication multiplication;
Logger logger;


void setup() {
	Serial.begin(9600);
	Timer1.initialize();
	Timer1.attachInterrupt( Bot::update,  BOT_TIME_INCREMENT_MICROS);

	multiplication.input = time;
	multiplication.multiplier = 0.0000005;
	
	logger.input = multiplication;
	logger.interval = 50;
}


void loop() {

}
