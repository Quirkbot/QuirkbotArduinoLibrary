#ifndef QuirkBug_h_
#define QuirkBug_h_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Arduino.h"
#include "Constants.h"

#include "Mathematics.h"
#include "Conversion.h"
#include "AnalogSensor.h"
#include "SonarSensor.h"
#include "Led.h"
#include "Buzzer.h"
#include "Servo.h"
#include "Wave.h"
#include "Randomizer.h"
#include "Time.h"
#include "Profile.h"
#include "Monitor.h"
#include "List.h"
#include "Sequence.h"

/**
 * Hack the setup() call, so we can initialize the QuirkBug before
 * everything else.
 **/
void _setup();
void setup(){

	Serial.begin(9600);

	// Setup the timer interrupt
	cli();//stop interrupts

	/*
	// Setup Timer 1 at 1KHz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set timer count for 1khz increments
	OCR1A = (F_CPU) / ((long)BOT_TIME_INCREMENT_MICROS * 8) - 1;
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS11 bit for 8 prescaler
	TCCR1B |= (1 << CS11);  
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
	*/

	
	// Setup Timer 2 
	/*TCCR2A = 0;// set entire TCCR2A register to 0
	TCCR2B = 0;// same for TCCR2B
	TCNT2  = 0;//initialize counter value to 0
	// set compare match register for 8khz increments
	OCR2A = (F_CPU) / ((long)BOT_TIME_INCREMENT_MICROS * 64) - 1 ;
	// turn on CTC mode
	TCCR2A |= (1 << WGM21);
	// Set CS22 bit for 64 prescaler
	TCCR2B |= ((1<<CS22) | (0<<CS21) | (0<<CS20));  
	// enable timer compare interrupt
	TIMSK2 |= (1 << OCIE2A);*/
	
	
	sei();//allow interrupts

	// Turn off RX and TX leds
	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	// Call sketch's setup()
	_setup();	
}
#define setup() _setup()

void loop(){
	Bot::update();
}

// Interrupt
/*ISR(TIMER2_COMPA_vect){
	cli();
	Bot::update();
	sei();
}*/

#endif