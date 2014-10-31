// Include the Quirbot library
#include "Quirkbot.h"

// Create the Led object
Led led;

void start(){
	// Connect the Led (long leg) to pin number 5
    led.pin = 5;
    
    // Turn the Led on, byt setting it's in value to 1.
    // After you get this code running, try changing it for numbers between
	// 0 and 1 and see how it affects the led light.
    led.in = 1;
}