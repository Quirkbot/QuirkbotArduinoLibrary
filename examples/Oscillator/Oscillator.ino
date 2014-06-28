#include <QuirkBug.h>

#include <SonarSensor.h>
#include <Led.h>
#include <Oscillator.h>
#include <Logger.h>

Oscillator osc1;
Led led1;

Oscillator osc2;
Led led2;

SerialPrint print;

void setup() {	

	osc1.duration = 0.5;
	//osc1.type = OSC_SINE; // DEFAULT
	//osc1.type = OSC_SQUARE;
	//osc1.type = OSC_PULSE;
	//osc1.type = OSC_TRIANGLE;
	//osc1.type = OSC_RAMP_UP;
	//osc1.type = OSC_RAMP_DOWN;

	osc2.duration = 0.5;
	osc2.offset = 0.5;


	led1.pin = 9;
	led1.input.connect(osc1.output);

	led2.pin = 10;
	led2.input.connect(osc2.output);

}


void loop(){}