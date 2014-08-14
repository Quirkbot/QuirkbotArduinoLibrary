#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

#include "Constants.h"

#include "Mathematics.h"
#include "Converter.h"
#include "AnalogSensor.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"
#include "Servo.h"
#include "Wave.h"
#include "Randomizer.h"
#include "Time.h"
#include "Profile.h"
#include "Monitor.h"
#include "List.h"
#include "Sequence.h"
#include "Gate.h"

void start();

void setup(){

	Serial.begin(115200);

	PORTD &= ~(1<<5);
	PORTB &= ~(1<<0);

	start();	
}

void loop(){
	Bot::update();
}

#endif