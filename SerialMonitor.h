#ifndef SerialMonitor_h_
#define SerialMonitor_h_

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "HasInterval.h"
#include "HasInputCollection.h"


class SerialMonitor:
public Node,
public HasInterval,
public HasInputCollection<float>{
	public:
	
	SerialMonitor():
	HasInterval
		(this),
	HasInputCollection<float>
		(this){
		interval = 0.1;
	};

	void onInterval();
};

void SerialMonitor::onInterval(){
	if(!inputCollection.size()) return;

	for(int i = 0; i < inputCollection.size(); i++){
		Serial.print(inputCollection[i]->get(), 3);
		Serial.print("\t");
	}
	Serial.print("\n");
}

#endif
