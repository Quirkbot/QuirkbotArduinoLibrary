#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

#include "CommonNodeIncludes.h"

#include "Mathematics.h"
#include "Converter.h"
#include "AnalogSensor.h"
#include "DigitalSensor.h"
#include "Sonar.h"
#include "Led.h"
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
	// Everything in the back off
	/*pinMode(LLB, OUTPUT);
	pinMode(RLB, OUTPUT);
	pinMode(RAB, OUTPUT);
	pinMode(HB, OUTPUT);
	pinMode(LAB, OUTPUT);*/
	digitalWrite(LLB, LOW);
	digitalWrite(RLB, LOW);
	digitalWrite(RAB, LOW);
	digitalWrite(HB, LOW);
	digitalWrite(LAB, LOW);
	// Mouth off
	PORTD &= ~(1<<5);
 	PORTB &= ~(1<<0);

 	// Start serial
 	Serial.begin(9600);

	start();	
}

void loop(){
	Bot::update();
}

#endif