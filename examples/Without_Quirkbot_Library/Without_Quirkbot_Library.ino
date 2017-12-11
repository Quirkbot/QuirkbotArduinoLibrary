// include the watchdog header:
#include <avr/wdt.h>

// create your variables and functions here:

void setup(){
	// put your setup code here, to run once:

}

void loop(){
	// reset the watchdog regularly, to avoid making the board go
	// into bootloader mode:
	wdt_reset();

	// put your main code here, to run repeatedly:

}
