#ifndef QuirkBug_h_
#define QuirkBug_h_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Arduino.h"
#include "Constants.h"
#include "Bot.h"
#include "Node.h"
#include "Updatable.h"

/**
 * Hack the setup() call, so we can initialize the QuirkBug before
 * everything else.
 **/
void _setup();
void setup(){

	Serial.begin(9600);

	// Setup the timer interrupt
	TCCR1A = 0;
	TCCR1B = _BV(WGM13); 
	unsigned char bits;
	long cycles = (F_CPU / 2000000) * BOT_TIME_INCREMENT_MICROS;
	long resolution = 65536;// 16 bits
	if(cycles < resolution)					bits = _BV(CS10);            // full
	else if((cycles >>= 3) < resolution)	bits = _BV(CS11) | _BV(CS10);// /64
	else if((cycles >>= 2) < resolution)	bits = _BV(CS12);			 // /256
	else if((cycles >>= 2) < resolution)	bits = _BV(CS12) | _BV(CS10);// /1024
	else		cycles = resolution - 1,	bits = _BV(CS12) | _BV(CS10);// maximum
	char oldSREG = SREG;
	cli();
	ICR1 = cycles;
	SREG = oldSREG;
	TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
	TCCR1B |= bits;
	TIMSK1 = _BV(TOIE1);
	TCCR1B |= bits;

	// Call sketch's setup()
	_setup();	
}
#define setup() _setup()

// Interrupt
ISR(TIMER1_OVF_vect){
	Bot::update();
}

#endif