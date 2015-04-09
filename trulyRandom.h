#ifndef trulyRandom_h_
#define trulyRandom_h_
// from:  https://sites.google.com/site/astudyofentropy/project-definition/
//           timer-jitter-entropy-sources/entropy-library

#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/atomic.h>
#define randomSeed(s) srandom(s)

volatile uint32_t __randomizedSeed;
volatile int8_t __entropy;
 

// Higher entropy, longer generation time
void trulyRandomSeed(int8_t entropy = 32){ 
	__randomizedSeed = 0;
	__entropy = entropy; 
	
	// Timer on
	cli();
	MCUSR = 0;
	_WD_CONTROL_REG |= (1<<_WD_CHANGE_BIT) | (1<<WDE); 
	_WD_CONTROL_REG = (1<<WDIE);
	sei();
 
	// Wait for seed
	while (__entropy > 0);
 
	// Timmer off
	cli();
	MCUSR = 0;
	_WD_CONTROL_REG |= (1<<_WD_CHANGE_BIT) | (0<<WDE); 
	_WD_CONTROL_REG = (0<< WDIE);
	sei();

	// Apply seed
	randomSeed(__randomizedSeed);
}
int trulyRandom(int min, int max, int8_t entropy = 32){
	trulyRandomSeed(entropy);
	return random(min, max);
}
byte trulyRandomUuidComponent(int8_t entropy = 32){
	byte t = trulyRandom(0,3, entropy);
	switch(t){
		case 0:
			return '0' + trulyRandom(0,9, entropy);
		case 1:
			return 'a' +  trulyRandom(0,26, entropy);
		case 2:
			return 'A' +  trulyRandom(0,25, entropy);
	}
}
 
ISR(WDT_vect){
	__entropy--;
	__randomizedSeed = __randomizedSeed << 8;
	__randomizedSeed = __randomizedSeed ^ TCNT1L;
}

#endif;