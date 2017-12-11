#include "Quirkbot.h"

// Create one node for the wave and one for the led
Wave wave;
Led led;

void setup(){
	// set the wave lengh to 1 second
	wave.length = 1;

	// set where the led is (LE = "left eye")
	led.place = LE;

	// connect the light of the led to the wave out value
	led.light.connect(wave.out);
}

void loop(){
	// nothing to do on the loop
}
