#include "Quirkbot.h"

Wave wave;
Converter converter;

ServoMotor servo;

SerialMonitor monitor;

void start(){
	wave.duration = 5;

	converter.in = wave.out;
	converter.inMin = 0;
	converter.inMax = 1;
	converter.outputMin = 0.47;
	converter.outputMax = 0.53;

	servo.pin = 8;
	servo.in = converter.out;

/*	monitor.add(wave);
	monitor.add(waveConverter);
	monitor.add(sonar);
	monitor.add(sonarConverter);*/
}


	//wave.output.connect(converter.in);