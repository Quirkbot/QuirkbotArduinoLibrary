#ifndef SerialMonitor_h_
#define SerialMonitor_h_

#include "CommonNodeIncludes.h"

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
	if(!items.size()) return;

	for(int i = 0; i < items.size(); i++){
		Serial.print(i);
		Serial.write(": ");
		Serial.print(items[i]->get(), 3);
		Serial.write("\t");
	}
	Serial.write("\n");
}

#endif
