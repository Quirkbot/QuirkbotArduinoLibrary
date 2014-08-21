#Anatomy of a Quirbot program


## Hello world

This simple program makes a Led pulsate.

	#include "Quirkbot.h"
	
	Led led;
	Wave wave;
	
	void start(){
		led.pin = 3;
		led.connect(wave);
	}
	
####Let's break it apart...

**Load the Quirbot library. Without it, nothing works.**


    #include "Quirkbot.h"
*This will always be the first line of your program.*


**Declare the nodes. Everything you do in the Quirbot, you do by creating nodes and connecting them to each other**

 	Led led;
	Wave wave;
	
*Here we create two nodes, ````led```` and ````wave````.*

*The ````led```` is a node of the type ```Led``` (notice the capital letter) and represents a real led lamp in the physical world.*

*The ````wave```` is a node of the type ```Wave``` (again, notice the capital letter). A wave represents an oscillating value (a number that goes from 0 to 1 in a continous loop).*

**The start of your program. Here is where you make the *actual* program, by conneting and configuring your nodes.**

    void start(){
        led.pin = 3;
        led.connect(wave);
    }


*The line ```led.pin = 3;```  configures the ```led``` node. It defines in which pin the lamp is connected to.*


*The line ``` led.connect(wave);``` connects the ```led``` node to the ```wave``` node. Now the light of the lamp will follow oscillating values of the wave; whent the wave is 0, the light will be off, when the wave is 1, the light will be on it's full brighteness.*

---

#.connect( ) & .control

---

#.connect( ) & .control