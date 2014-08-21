#ifndef Profile_h_
#define Profile_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Streams.h"
#include "Output.h"

class SystemMemory :
public Node,
public HasInterval,
public OutputStream<float>
{
	public:

	SystemMemory():
	HasInterval
		(this),
	OutputStream<float>
		(ram){
		interval = 0.01;
	};

	void onInterval();

	Output<float> ram;

	private:

	static int getFreeRam();

};
int SystemMemory::getFreeRam(){
	extern int __heap_start, *__brkval; 
	int v; 
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
void SystemMemory::onInterval(){
	ram.set(getFreeRam());
}

#endif
