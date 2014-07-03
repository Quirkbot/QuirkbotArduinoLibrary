#ifndef Profile_h_
#define Profile_h_

#include "Bot.h"
#include "Node.h"
#include "HasInterval.h"
#include "Output.h"

class Profile :
public Node,
public HasInterval
{
	public:

	Profile():
	HasInterval
		(this){
		interval = 10;
	};

	void onInterval();

	Output<float> ram;
	Output<float> fps;

	private:

	static int getFreeRam();

};
int Profile::getFreeRam(){
	extern int __heap_start, *__brkval; 
	int v; 
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
void Profile::onInterval(){
	ram.set(getFreeRam());
	fps.set(1.0/(Bot::dtMicros / 1000000));
}

#endif
