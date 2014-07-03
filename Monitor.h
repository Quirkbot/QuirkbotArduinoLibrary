#ifndef Monitor_h_
#define Monitor_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "HasInputCollection.h"
#include "Input.h"
#include "Streams.h"

class Monitor:
public Node,
public HasInterval,
public HasInputCollection<float>{
	public:
	
	Monitor():
	HasInterval
		(this),
	HasInputCollection<float>
		(this){
		interval = 100;
	};

	void onInterval();
};

void Monitor::onInterval(){
	if(!inputCollection.size()) return;

	for(int i = 0; i < inputCollection.size(); i++){
		Serial.print(inputCollection[i]->get(), 3);
		Serial.print("\t");
	}
	Serial.print("\n");
}

#endif
