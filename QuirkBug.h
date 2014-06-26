#ifndef QuirkBug_h_
#define QuirkBug_h_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Arduino.h"
#include "Constants.h"
#include "Mathematics.h"


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