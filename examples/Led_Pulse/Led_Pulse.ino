// Include the Quirbot library
#include "Quirkbot.h"

// Create the Led object
Led led;
// Create the wave object (the wave will control the Led)
Wave wave;

void start(){
	// Connect the Led (long leg) to pin number 5 on the Arduino
    led.pin = 5;
    
	// Connect the wave.out to the led.in, in that way everytime the wave
    // changes, the Led will change too.
    wave.out.connect(led.in);
    
    // Set the wave duration to 2 senconds.
    // After you try this code for the fisrt time, try changing this value and
    // see how it affects the speed of the pulse.
    wave.duration = 2;
}