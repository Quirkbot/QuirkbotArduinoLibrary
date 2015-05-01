#include "SystemMemory.h"

SystemMemory::SystemMemory():
HasInterval
	(this),
HasOut
	(this){
	interval = 0.01;
}
int SystemMemory::getFreeRam(){
	extern int __heap_start, *__brkval; 
	int v; 
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
void SystemMemory::onInterval(){
	out.set(getFreeRam());
}