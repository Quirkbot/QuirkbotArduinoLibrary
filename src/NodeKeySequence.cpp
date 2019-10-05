#include "NodeKeySequence.h"

KeySequence::KeySequence():
HasInterval
	(this){
	registerInput(key);
	registerInput(holdTime);

	for (int i = 0; i < QB_MAX_SIMULTANEOUS_KEYS; ++i){
		scheduleKey[i] = 0;
		scheduleTime[i] = 0;
	}

	index = QB_MAX_SIMULTANEOUS_KEYS;

	key = 0;
	holdTime = 0;
};
KeySequence::~KeySequence(){}

void KeySequence::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &key){
		if(key.get() == NO_KEY) return;

		index++;
		if(index >= QB_MAX_SIMULTANEOUS_KEYS) index = 0;

		// Check if some key needs to be dropped
		if(scheduleKey[index] && ::millis() < scheduleTime[index]){
			Bot::releaseKey(scheduleKey[index]);
		}

		int currentKey = key.get();
		long currentTime = ::millis() + holdTime.get() * 1000;

		Bot::pressKey(currentKey);

		scheduleKey[index] = currentKey;
		scheduleTime[index] = currentTime;

		// Reset key internally to NO_KEY, so we can accept a stream of repeated
		// keys.
		key.value = NO_KEY;
	}

};

void KeySequence::onInterval(){
	for (int i = 0; i < QB_MAX_SIMULTANEOUS_KEYS; ++i) {
		unsigned int key = scheduleKey[i];
		unsigned long time =  scheduleTime[i];
		if(key == 0) continue;
		if(::millis() > time){
			Bot::releaseKey(key);
			scheduleKey[i] = 0;
		}
	}
}
