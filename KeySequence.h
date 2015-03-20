#ifndef KeySequence_h_
#define KeySequence_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_SIMULTANEOUS_KEYS 20

class KeySequence :
public Node,
public HasIn<float>,
public HasInterval
{
	public:
	
	KeySequence():
	HasIn<float>
		(this),
	HasInterval
		(this){
		registerInput(hold);

		hold = 0.3;

		for (int i = 0; i < QB_MAX_SIMULTANEOUS_KEYS; ++i){
			schedule[i][0] = 0;
			schedule[i][1] = 0;
		}

		index = 0;
	};

	Input<float> hold;


	protected:
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);

	long schedule[QB_MAX_SIMULTANEOUS_KEYS][2];
	int index;
};

void KeySequence::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		// Check if some key needs to be dropped
		if(schedule[index][0] && Bot::millis < schedule[index][1]){
			Bot::releaseKey(schedule[index][0]);
		}


		int currentKey = in.get();
		long currentTime = Bot::millis + hold.get() * 1000;

		Bot::pressKey(currentKey);

		schedule[index][0] = currentKey;
		schedule[index][1] = currentTime;

		index++;
		if(index == QB_MAX_SIMULTANEOUS_KEYS) index = 0;

		
	}

};

void KeySequence::onInterval(){
	for (int i = 0; i < QB_MAX_SIMULTANEOUS_KEYS; ++i) {
		int key = schedule[i][0];
		long time =  schedule[i][1];
		Serial.print(key);
		Serial.print('\t');
		Serial.print(time);
		Serial.print('\t');
		if(!key) continue;
		if(Bot::millis > time){
			Bot::releaseKey(key);
			schedule[i][0] = 0;
		}
	}
	Serial.println(' ');
}


#endif
