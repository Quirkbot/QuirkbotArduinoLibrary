#include <QuirkBug.h>

Wave wave;
Sequence sequence;
Buzzer buzzer;
Monitor monitor;

void setup() {
	wave.duration = 4;
	wave.type = WAVE_PULSE;

	buzzer.pin = 4;
	buzzer.connect(sequence);

	sequence.add(NOTE_C3);
	sequence.add(NOTE_A4);
	sequence.add(NOTE_G3);
	sequence.add(NOTE_E3);
	sequence.add(NO_NOTE);
	sequence.trigger.connect(wave);
	
	monitor.add(wave);
	monitor.add(sequence);
}