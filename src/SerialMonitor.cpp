#include "SerialMonitor.h"

SerialMonitor::SerialMonitor():
HasInterval
	(this){
	registerInputCollection(items);
	interval = 0.1;
}
SerialMonitor::~SerialMonitor(){}
void SerialMonitor::onInterval(){
	if(!items.collection.size()) return;

	for(int i = 0; i < items.collection.size(); i++){
		Serial.print(i);
		Serial.write(": ");
		Serial.print(items.collection[i]->get(), 3);
		Serial.write("\t");
	}
	Serial.write("\n");
}
