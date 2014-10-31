#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

#include "Mathematics.h"
#include "Converter.h"
#include "AnalogSensor.h"
#include "Sonar.h"
#include "Led.h"
#include "RGBLed.h"
#include "Buzzer.h"
#include "ServoMotor.h"
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

	Serial.begin(9600);

	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	start();	
}

void loop(){
	Bot::update();
}

#endif