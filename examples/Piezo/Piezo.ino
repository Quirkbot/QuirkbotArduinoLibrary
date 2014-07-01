#include <QuirkBug.h>

Wave wave;
List list;
Buzzer buzzer;;
Monitor monitor;


void setup() {	
	wave.duration = 1000;
	wave.type = WAVE_RAMP_UP;

	list.add(NOTE_C4);
	list.add(NOTE_A4);
	
	list.connect(wave);
	
	buzzer.pin = 4;
	buzzer.connect(list);

	monitor.add(wave);
	monitor.add(list);
}
