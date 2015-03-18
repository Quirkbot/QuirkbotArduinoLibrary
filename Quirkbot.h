#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

#include "CommonNodeIncludes.h"

#include "Mathematics.h"
#include "Converter.h"
#include "AnalogSensor.h"
#include "DigitalSensor.h"
#include "MakeyTouchSensor.h"
#include "SqueezeSensor.h"
#include "Sonar.h"
#include "VoltageOutput.h"
#include "Led.h"
#include "DualColorLed.h"
#include "RGBLed.h"
#include "Buzzer.h"
#include "ServoMotor.h"
#include "ContinuousServoMotor.h"
#include "Wave.h"
#include "Randomizer.h"
#include "Time.h"
#include "SystemMemory.h"
#include "SerialMonitor.h"
#include "List.h"
#include "Sequence.h"
#include "Gate.h"

void start();

void setup(){

 	// Start serial
 	Serial.begin(115200);

 	// Start Keyboard
 	Keyboard.begin();
 	
 	// Force mouth to turn off (only used if you have to use the LillyPad USB)
 	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	start();	
}

void loop(){
	Bot::update();
}

#endif