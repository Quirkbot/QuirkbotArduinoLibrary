#ifndef trulyRandom_h_
#define trulyRandom_h_
// from:  https://sites.google.com/site/astudyofentropy/project-definition/
//           timer-jitter-entropy-sources/entropy-library
#include "Arduino.h"
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/atomic.h>

#define randomSeed(s) srandom(s) 

// Higher entropy, longer generation time
void trulyRandomSeed(int8_t entropy = 32);
int trulyRandom(int min, int max, int8_t entropy = 32);
byte trulyRandomUuidComponent(int8_t entropy = 32);

#endif;