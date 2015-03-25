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
			scheduleKey[i] = 0;
			scheduleTime[i] = 0;
		}

		index = 0;
	};

	Input<float> hold;


	protected:
	void onInterval();
	void onInternalInputChange(BaseInput &internalInput);

	int scheduleKey[QB_MAX_SIMULTANEOUS_KEYS];
	long scheduleTime[QB_MAX_SIMULTANEOUS_KEYS];
	int index;
};

void KeySequence::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		// Check if some key needs to be dropped
		if(scheduleKey[index] && Bot::millis < scheduleTime[index]){
			Bot::releaseKey(scheduleKey[index]);
		}


		int currentKey = in.get();
		long currentTime = Bot::millis + hold.get() * 1000;

		Bot::pressKey(currentKey);

		scheduleKey[index] = currentKey;
		scheduleTime[index] = currentTime;

		index++;
		if(index == QB_MAX_SIMULTANEOUS_KEYS) index = 0;

		
	}

};

void KeySequence::onInterval(){
	for (int i = 0; i < QB_MAX_SIMULTANEOUS_KEYS; ++i) {
		int key = scheduleKey[i];
		long time =  scheduleTime[i];
		if(!key) continue;
		if(Bot::millis > time){
			Bot::releaseKey(key);
			scheduleKey[i] = 0;
		}
	}
}


#endif
