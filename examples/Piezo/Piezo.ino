#include <QuirkBug.h>

#include <Oscillator.h>
#include <Buzzer.h>

Oscillator osc;
Buzzer buzzer;

void setup() {	
	osc.duration = 0.6;
	
	buzzer.pin = 4;
	buzzer.input.connect(osc.output);
}

void loop(){

}