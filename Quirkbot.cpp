#include "Quirkbot.h"

volatile unsigned int qb_timer_count;

void setup(){
	Bot::beforeStart();
	start();
	Bot::afterStart();

	// Setup the timer interrupt
	TCCR4B = 7; // 1 - 187500 Hz, 2 - 93750 Hz, 3 - 46875 Hz, 4 - 23437 Hz, 5 - 11719 Hz, 6 - 5859 Hz, 7 - 2930 Hz
	TCCR4A = 0;
	TCCR4C = 0;
	TCCR4D = 0;
	TCCR4E = 0;
	TIFR4 = (1<<TOV4);
	TCNT4 = 0;
	//OCR4C = 1024;
	TIMSK4 = (1<<TOIE4);
	PLLFRQ = 0b01011010;
	//PLLFRQ = (PLLFRQ&0xCF)|0x30;
}
void loop(){
	Bot::update();
}

ISR(TIMER4_OVF_vect) {
	sei();
	Bot::interruptUpdate();
	cli();
}
