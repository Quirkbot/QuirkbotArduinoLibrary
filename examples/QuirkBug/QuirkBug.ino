#include <TimerOne.h>
#include <StandardCplusplus.h>
#include <QuirkBug.h>

#include <nodes/Time.h>
#include <nodes/Sine.h>
#include <nodes/Logger.h>



Time time;
Sine sine;
Logger logger;


void setup() {
	Serial.begin(9600);
	Timer1.initialize();
	Timer1.attachInterrupt( Bot::update,  BOT_TIME_INCREMENT_MICROS);

	sine.source = time.seconds;
	logger.source = sine.result;

}


void loop() {
	//tested.dispatch(time);
	delay(1000);
}
