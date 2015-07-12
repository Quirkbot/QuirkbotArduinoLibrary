#include "SerialMonitor.h"

SerialMonitor::SerialMonitor():
HasInterval
	(this),
HasInputCollection
	(this){
	interval = 0.1;
}
SerialMonitor::~SerialMonitor(){}
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