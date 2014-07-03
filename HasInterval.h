#ifndef HasInterval_h_
#define HasInterval_h_

#include "Bot.h"
#include "Updatable.h"
#include "Input.h"
#include "Output.h"

class Node;
class Updatable;

class HasInterval:
public Updatable{
	public:
	HasInterval(){
		interval = 1;
	};

	void update(){

		if((int)(Bot::millis) % (int)interval == 0
			&& lastMillis != Bot::millis){
			
			lastMillis = Bot::millis;
			onInterval();
		}
	};

	virtual void onInterval(){};

	Input<float> interval;

	private:
	int lastMillis;
};

#endif
