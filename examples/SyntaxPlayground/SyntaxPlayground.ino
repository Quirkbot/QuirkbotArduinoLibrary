#include "Quirkbot.h"

Wave wave;
Converter waveConverter;

Sonar sonar;
Converter sonarConverter;

Sequence sequence;

List notes;

Minimum minimum;

ServoMotor servo;
Led led;
Buzzer buzzer;
RGBLed rgbLed;

SerialMonitor monitor;

void start(){
	servo.pin.connect(5);
	sonar.pin = 7;
	led.pin = 6;
	buzzer.pin = 4;
	rgbLed.pinR = 5;
	rgbLed.pinG = 5;
	rgbLed.pinB = 5;

	wave.type = WAVE_SQUARE;
	waveConverter.set(0, 1, 1, 0);
	sonarConverter.set(0.4, 0.5, 0, 1);


	sequence.add(1);
	sequence.add(0.5);
	sequence.add(0.4);
	sequence.add(1);
	sequence.add(0);

	notes.add(NOTE_C4);
	notes.add(NOTE_A4);
	notes.add(NOTE_D4);
	notes.add(NOTE_E3);
	notes.add(NOTE_C2);

	/*waveConverter.in.connect(wave.out);
	wave.out.connect(waveConverter.in);

	waveConverter.in = wave.out;
	wave.out = waveConverter.in;*/

	sonarConverter.connect(sonar);
	
	minimum.connect(waveConverter);
	minimum.connect(sonarConverter);
	
	sequence.trigger(sonarConverter);

	notes.connect(minimum);

	servo.connect(minimum);
	buzzer.connect(notes);

	monitor.add(wave);
	monitor.add(waveConverter);
	monitor.add(sonar);
	monitor.add(sonarConverter);
}