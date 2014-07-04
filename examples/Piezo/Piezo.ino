#include <QuirkBug.h>

Wave wave;
List list;
Buzzer buzzer;
Profile profile;
Monitor monitor;

void setup() {
	wave.duration = 1.5;
	wave.type = WAVE_RAMP_UP;

	list.add(NOTE_C3);
	list.add(NOTE_A4);
	list.add(NOTE_G3);
	list.add(NOTE_E3);
	list.add(NO_NOTE);
	
	list.connect(wave);
	
	buzzer.pin = 4;
	buzzer.connect(list);

	monitor.add(wave);
	monitor.add(list);
	monitor.add(profile.ram);
}