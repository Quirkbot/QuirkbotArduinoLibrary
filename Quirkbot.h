#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

// Keyboard & Mouse
#include "KeyPress.h"
#include "KeySequence.h"

// Signal
#include "Wave.h"
#include "Randomizer.h"

// Sensors
#include "AnalogSensor.h"
#include "DigitalSensor.h"
#include "MakeyTouchSensor.h"
#include "SqueezeSensor.h"
#include "Sonar.h"

// Light
#include "Led.h"
#include "DualColorLed.h"
#include "RGBLed.h"

// Movement
#include "ServoMotor.h"
#include "ContinuousServoMotor.h"

// Sound
#include "Buzzer.h"

// General
#include "VoltageOutput.h"

// Logic
#include "Mathematics.h"
#include "Converter.h"
#include "List.h"
#include "Sequence.h"
#include "Gate.h"

// Debug
#include "SystemMemory.h"
#include "SerialMonitor.h"
#include "Time.h"

void start();
void setup();
void loop();

#endif