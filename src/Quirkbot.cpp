#include "Quirkbot.h"

void Quirkbot_::setup(void){
	Bot::start();
	// Setup the timer interrupt
	TCCR4B = 7;
	TCCR4A = 0;
	TCCR4C = 0;
	TCCR4D = 0;
	TCCR4E = 0;
	TIFR4 = (1<<TOV4);
	TCNT4 = 0;
	TIMSK4 = (1<<TOIE4);
	PLLFRQ = 0b01011010;
}
void Quirkbot_::loop(void){
	Bot::update();
}
void Quirkbot_::delay(unsigned long ms){
	unsigned long deadline = Bot::millis + ms;
	while(Bot::millis < deadline){
		Bot::update();
	}
}
void Quirkbot_::delayMicroseconds(unsigned int us){
	unsigned long deadline = Bot::micros + us;
	while(Bot::micros < deadline){
		Bot::update();
	}
}
void Quirkbot_::disableSerialReport(void){
	Bot::serialReportEnabled = false;
}
void Quirkbot_::enableSerialReport(void){
	Bot::serialReportEnabled = true;
}
ISR(TIMER4_OVF_vect) {
	Bot::interruptUpdate();
}

Quirkbot_ Quirkbot;
