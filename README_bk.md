#Quirbot documentation

<a name=menu></a>
###Nodes
1. Physical Components
	- [Sonar](#Sonar)
	- [AnalogSensor](#AnalogSensor)
	- [Led](#Led)
	- [ServoMotor](#ServoMotor)
	- [Buzzer](#Buzzer)
2. Generators
	- [Wave](#Wave)
	- [Randomizer](#Randomizer)
    - [Time](#Time)
    - [Fader](#Fader)
3. Flow Control
	- [Sequence](#Sequence)
	- [List](#List)
    - [Gate](#Gate)
4. Debugging
    - [SerialMonitor](#SerialMonitor)
5. Math
    - Operations
        - [Addition](#Addition)
        - [Subtraction](#Subtraction)
        - [Multiplication](#Multiplication)
        - [Division](#Division)
        - [Power](#Power)
        - [SquareRoot](#SquareRoot)
        - [Modulo](#Modulo)
        - [Maximum](#Maximum)
        - [Minimum](#Minimum)
        - [Logarithm](#Logarithm)
        - [Logarithm10](#Logarithm10)
     - Rounding
        - [Round](#Round)
        - [Ceiling](#Ceiling)
        - [Floor](#Floor)
        - [Absolute](#Absolute)
    - Trigonmetry
        - [Sine](#Sine)
        - [ArcSine](#ArcSine)
        - [Cosine](#Cosine)
        - [ArcCosine](#ArcCosine)
        - [Tangent](#Tangent)
        - [ArcTangent](#ArcTangent)

---

<a name=Sonar></a>

[↑ Back to table of contents](#menu)

#Sonar ````Output >>````

Measure distance from objects.
##Examples
###Monitor distance

Read the data from the sensor and log it using serial communication
	
	#include "Quirkbot.h"
	
	Sonar sonar;
	SerialMonitor monitor;
	
	void start(){
		sonar.pin = 7;
		
		monitor.add(sonar);
	}
	
	
---

<a name=AnalogSensor></a>

[↑ Back to table of contents](#menu)

#AnalogSensor ````Output >>````

Measures eletric resitance. Can be used with photo sensors, humidity sensors, potenciometers, etc.
##Examples
###Light sensor

Read the data from the sensor and log it using serial communication
	
	#include "Quirkbot.h"
	
	AnalogSensor sensor;
	SerialMonitor monitor;
	
	void start(){
		sensor.pin = 7;
		
		monitor.add(sensor);
	}
	







--------------------------------
**Category:** *[Sensor](#Sensor), [HasPin](#HasPin), [HasInterval](#HasInterval), [OutputStream](#OutputStream)*

##Properties

###pin

Selects which digital pin the component is connected to.
	
	Sonar sonar;
	
	void start(){
		sonar.pin = 7;
	}
	

###smoothing

How much smoothing will be applied to the incoming signal.

*Set ```0``` for no smoothing (raw signal) or ````1```` for very strong filtering.*

*The default value is ```0.5```*.


	
	Sonar sonar;
	
	void start(){
		sonar.pin = 7;
		sonar.smoothing = 0.7;
	}

###interval

How often (in seconds) will the sensor report it's readings.

*The smallest possible interval is ```0.05```*.

*The default value is ```0.1```*.


	
	Sonar sonar;
	
	void start(){
		sonar.pin = 7;
		sonar.smoothing = 0.7;
		sonar.interval = 0.5;
	}


---

<a name=AnalogSensor></a>

[↑ Back to table of contents](#menu)

#AnalogSensor ````Output >>````


Measures eletric resitance. Can be used with photo sensors, humidity sensors, potenciometers, etc.

**Category:** *[Sensor](#Sensor), [HasPin](#HasPin), [HasInterval](#HasInterval), [OutputStream](#OutputStream)*

##Properties

###pin

Selects which analog pin the component is connected to.
	
	AnalogSensor sensor;
	
	void start(){
		sensor.pin = A0;
	}
	

###smoothing

How much smoothing will be applied to the incoming signal.

*Set ```0``` for no smoothing (raw signal) or ````1```` for very strong filtering.*

*The default value is ```0.5```*.


	
	AnalogSensor sensor;
	
	void start(){
		sensor.pin = A0;
		sensor.smoothing = 0.7;
	}

###interval

How often (in seconds) will the sensor report it's readings.

*The default value is ```0.1```*.


	
	AnalogSensor sensor;
	
	void start(){
		sensor.pin = A0;
		sensor.smoothing = 0.7;
		sensor.interval = 0.5;
	}

---

<a name=Led></a>

[↑ Back to table of contents](#menu)

#Led ````>> Input````


Light Emiting Diode. It blinks :).

**Category:** *[HasPin](#HasPin), [InputStream](#InputStream)*

##Properties

###pin

Selects which pwm pin the component is connected to.
	
	Led led;
	
	void start(){
		led.pin = 3;
	}
	
###control

Set the brigtheness of the lamp.

*Set ```0``` for no brightness (led off), ````1```` for full brightness or a fraction (eg. ```0.3```) for a dimmend brightness.*

*The default value is ```0```*.

	
	Led led;
	
	void start(){
		led.pin = 3;
		led.control = 0.5;
	}
	

##Methods

###connect(OutputStream& output)

Connects to an output node, causing the light to update everytime  there is a change in the signal.
	
	Led led;
	
	void start(){
		led.pin = 3;
	}
	

