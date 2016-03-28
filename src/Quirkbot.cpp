#include "Quirkbot.h"

Quirkbot_::Quirkbot_(){
	inited = false;
}
void (setup)(){
	Quirkbot.setup_();
	setup_();
	Quirkbot.afterSetup_();
}
void Quirkbot_::setup_(void){
	inited = true;
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
void Quirkbot_::afterSetup_(void){
	Bot::afterStart();
}
void (loop)(){
	Quirkbot.loop_();
	loop_();
}
void Quirkbot_::loop_(void){
	if(!inited) {
		return;
	}
	Bot::update();
}
void Quirkbot_::delay_(unsigned long ms){
	if(!inited) {
		return (delay)(ms);
	}
	unsigned long deadline = ::millis() + ms;
	while(::millis() < deadline){
		Bot::update();
	}
}
void Quirkbot_::delayMicroseconds_(unsigned long us){
	if(!inited) {
		return (delayMicroseconds)(us);
	}
	if(us > 1000){
		return delay_((float)us / 1000.0);
	}
	unsigned int deadline = ::micros() + us;
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
