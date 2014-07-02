#include <QuirkBug.h>

Wave wave;
List list;
Buzzer buzzer;
Profile profile;
Monitor monitor;


void setup() {	
	delay(1000);

	wave.duration = 1000;
	wave.type = WAVE_RAMP_UP;

	list.add(NOTE_C1);
	//list.add(NOTE_C1);
	//list.add(NOTE_G1);
	//list.add(NOTE_E1);
	//list.add(NOTE_A1);
	//list.add(NOTE_D1);
	//list.add(NOTE_G1);
	//list.add(NOTE_E1);
	
	//list.connect(wave);
	
	//buzzer.pin = 4;
	//buzzer.connect(list);

	monitor.add(wave);
	monitor.add(list);
	monitor.add(profile.ram);
	monitor.add(profile.fps);
	
}
