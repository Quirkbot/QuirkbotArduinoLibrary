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
	cli();//stop interrupts
	//set timer1 interrupt at 1kHz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set timer count for 1khz increments
	OCR1A = 1999;// = (16*10^6) / (1000*8) - 1
	//had to use 16 bit timer1 for this bc 1999>255, but could switch to timers 0 or 2 with larger prescaler
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS11 bit for 8 prescaler
	TCCR1B |= (1 << CS11);  
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
	sei();//allow interrupts

	// Setup the timer interrupt
	/*TCCR1A = 0;
	TCCR1B = _BV(WGM13); 
	unsigned char bits;
	const unsigned long cycles cycles = (F_CPU / 2000000) * BOT_TIME_INCREMENT_MICROS;
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
	TCCR1B |= bits;*/


	
	// Setup the timer interrupt
	/*TCCR1B = _BV(WGM13); 
	TCCR1A = 0;	
	unsigned char bits;
	unsigned long cycles = (F_CPU / 2000000) * BOT_TIME_INCREMENT_MICROS;
	if (cycles < 65536UL)  bits = _BV(CS10);
	if (cycles < 65536UL * 8) bits = _BV(CS11);
	if (cycles < 65536UL * 64) bits = _BV(CS11) | _BV(CS10);
	if (cycles < 65536UL * 256) bits = _BV(CS12);
	if (cycles < 65536UL * 1024) bits = _BV(CS12) | _BV(CS10);
	else bits = _BV(CS12) | _BV(CS10);
	ICR1 = cycles;
	TCCR1B = _BV(WGM13) | bits;
	TIMSK1 = _BV(TOIE1);*/
	

	// Turn off RX and TX leds
	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	// Call sketch's setup()
	_setup();	
}
#define setup() _setup()

// Interrupt
ISR(TIMER1_COMPA_vect){
	cli();
	Bot::update();
	sei();
}

#endif