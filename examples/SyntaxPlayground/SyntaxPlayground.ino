#include "Quirkbot.h"

Wave wave;
Converter converter;

ServoMotor servo;

SerialMonitor monitor;

void start(){
	wave.duration = 5;

	converter.input = wave.output;
	converter.inputMin = 0;
	converter.inputMax = 1;
	converter.outputMin = 1.0;
	converter.outputMax = 0.0;

	servo.pin = 8;
	sonarervo.input = converter.output;

/*	monitor.add(wave);
	monitor.add(waveConverter);
	monitor.add(sonar);
	monitor.add(sonarConverter);*/
}


	//wave.output.connect(converter.input);