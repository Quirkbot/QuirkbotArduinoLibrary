#Quirbot API documentation

<a name=menu></a>
###Nodes
1. Physical Components
	- [Sonar](#Sonar)
	- [AnalogSensor](#AnalogSensor)
	- [Led](#Led)
	- [RGBLed](#RGBLed)
	- [ServoMotor](#ServoMotor)
	- [Buzzer](#Buzzer)
    - *[CapacitativeSensor](#CapacitativeSensor)
2. Generators
	- [Wave](#Wave)
	- [Randomizer](#Randomizer)
    - [Time](#Time)
    - *[Fader](#Fader)
3. Flow Control
	- [Sequence](#Sequence)
    - *[SmoothSequence](#SmoothSequence)(?maybe chaning a fader is the best)
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
	


---

<a name=Led></a>

[↑ Back to table of contents](#menu)

#Led ````>> Input````


Light Emiting Diode. It blinks :).

##Examples
###Adjusting the light level

Set's the led light level to a specific value.
	
	#include "Quirkbot.h"
	
	Led led;
	
	void start(){
		led.pin = 3;
		
		led.control = 0.5; // half brightenss
	}
	
###Pulse

Make the led pulse by connecting it to a sine wave;
	
	#include "Quirkbot.h"
	
	Led led;
	Wave wave;
	
	void start(){
		led.pin = 3;
		led.connect(wave); // the wave value will control the brighteness
		
		wave.duration = 3; // 3 sencods cyle
	}
	
###Strobe

Make the led flicker by connecting it to a fast square wave;
	
	#include "Quirkbot.h"
	
	Led led;
	Wave wave;
	
	void start(){
		led.pin = 3;
		led.connect(wave); // the wave value will control the brighteness
		
		wave.duration = 0.4; // 0.4 seconds cyle
		wave.type = WAVE_SQUARE; // square wave to remove fading
	}

---

<a name=RGBLed></a>

[↑ Back to table of contents](#menu)

#RGBLed ````>> Input````


A HSL (hue, saturation, luminosity) controller for RGB leds (or simply 3 individual leds - one red, one green one blue).
##Examples
###Rainbow

Cycle all different hue values, with a fixed brighteness.
	
	#include "Quirkbot.h"
	
	RGBLed led;
	
	Wave wave;
	
	void start(){
		led.pinR = 3;
		led.pinG = 5;
		led.pinB = 6;
		
		led.hue.connect(wave); // connect only the hue to the wave
		led.control = 1.0; // full brightenss
	}

###Fixed color

Set a specific color and pulse the light.
	
	#include "Quirkbot.h"
	
	RGBLed led;
	
	Wave wave;
	
	void start(){
		led.pinR = 3;
		led.pinG = 5;
		led.pinB = 6;
		
		led.hue = 0.5; // greenish
		led.connect(wave);  // the wave value will control the brighteness
	}

---

<a name=ServoMotor></a>

[↑ Back to table of contents](#menu)

#ServoMotor ````>> Input````


Controls the position of the servo arm (or speed and direction, if servo is continous).

##Examples
###Sweep

Moves the servo arm back-and-forth.
	
	#include "Quirkbot.h"
	
	ServoMotor servo;
	
	Wave wave;
	
	void start(){
		servo.pin = 2;
		servo.connect(wave);
	}
	
###Controlled by a sonar

Use the distance from a sonar to control the arm position.
	
	#include "Quirkbot.h"
	
	ServoMotor servo;
	Sonar sonar;

	void start(){
		sonar.pin = 7;
		servo.pin = 2;
		servo.connect(sonar);
	}

---

<a name=Buzzer></a>

[↑ Back to table of contents](#menu)

#Buzzer ````>> Input````

Controls the sound of a buzzer (piezzo or speaker) by producing a tone.

##Examples
###Playing a note

Plays a note.
	
	#include "Quirkbot.h"
	
	Buzzer buzzer;
	
	void start(){
		buzzer.pin = 2;
		buzzer.control = NOTE_A2; // Plays an "A"
	}
All avaiable notes:

    // Silence (same as zero)
    NO_NOTE	
    
    // Notes
    NOTE_B0	
    	
    NOTE_C1	
    NOTE_CS1
    NOTE_D1	
    NOTE_DS1
    NOTE_E1	
    NOTE_F1	
    NOTE_FS1
    NOTE_G1	
    NOTE_GS1
    NOTE_A1	
    NOTE_AS1
    NOTE_B1	
    
    NOTE_C2	
    NOTE_CS2
    NOTE_D2	
    NOTE_DS2
    NOTE_E2	
    NOTE_F2	
    NOTE_FS2
    NOTE_G2	
    NOTE_GS2
    NOTE_A2	
    NOTE_AS2
    NOTE_B2	
    
    NOTE_C3	
    NOTE_CS3
    NOTE_D3	
    NOTE_DS3
    NOTE_E3	
    NOTE_F3	
    NOTE_FS3
    NOTE_G3	
    NOTE_GS3
    NOTE_A3	
    NOTE_AS3
    NOTE_B3	
    
    NOTE_C4	
    NOTE_CS4
    NOTE_D4	
    NOTE_DS4
    NOTE_E4	
    NOTE_F4	
    NOTE_FS4
    NOTE_G4	
    NOTE_GS4
    NOTE_A4	
    NOTE_AS4
    NOTE_B4	
    
    NOTE_C5	
    NOTE_CS5
    NOTE_D5	
    NOTE_DS5
    NOTE_E5	
    NOTE_F5	
    NOTE_FS5
    NOTE_G5	
    NOTE_GS5
    NOTE_A5	
    NOTE_AS5
    NOTE_B5	
    
    NOTE_C6	
    NOTE_CS6
    NOTE_D6	
    NOTE_DS6
    NOTE_E6	
    NOTE_F6	
    NOTE_FS6
    NOTE_G6	
    NOTE_GS6
    NOTE_A6	
    NOTE_AS6
    NOTE_B6	
    
    NOTE_C7	
    NOTE_CS7
    NOTE_D7	
    NOTE_DS7
    NOTE_E7	
    NOTE_F7	
    NOTE_FS7
    NOTE_G7	
    NOTE_GS7
    NOTE_A7	
    NOTE_AS7
    NOTE_B7	
    
    NOTE_C8	
    NOTE_CS8
    NOTE_D8	
    NOTE_DS8
    
###Robot Sound

Plays random notes.
	
	#include "Quirkbot.h"
	
	Buzzer buzzer;
	Randomizer randomizer;
	
	void start(){
		buzzer.pin = 2;
		buzzer.connect(randomizer);
	}
	
	
###Sequence of note

Plays a sequence of notes in 3 seconds, repeating it every 5 seconds.
	
	#include "Quirkbot.h"
	
	Buzzer buzzer;
	Sequence sequence;
	Wave wave;
	
	void start(){
		buzzer.pin = 2;
		
		// Add notes to the sequence
		sequence.add(NOTE_C1);
		sequence.add(NOTE_D2);
		sequence.add(NOTE_A1);
		sequence.add(NOTE_C2);
		
		// Set the duration of the sequence
		sequence.duration = 3;
		
		// Set the wave peridod
		wave.duration = 5;
		
		// Use the wave to trigger the sequence.
		// Every time the wave hits '1', the sequence plays
		sequence.trigger(wave);
		
		// Connect the buzzer to the sequence
		buzzer.connect(sequence);
	}