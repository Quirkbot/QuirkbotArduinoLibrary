#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

#include "Mathematics.h"
#include "Converter.h"
#include "AnalogSensor.h"
#include "DigitalSensor.h"
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
	start();	
}

void loop(){
	Bot::update();
}

#endif