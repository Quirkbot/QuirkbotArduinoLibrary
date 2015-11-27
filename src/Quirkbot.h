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
#include "CircuitTouch.h"
#include "SqueezeSensor.h"
#include "IRProximity.h"
#include "LightSensor.h"
#include "Sonar.h"

// Light
#include "Led.h"
#include "DualColorLed.h"
#include "RGBLed.h"

// Movement
#include "ServoMotor.h"
#include "ContinuousServo.h"

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

class Quirkbot_{
	public:
		Quirkbot_();
		void setup_(void);
		void loop_(void);
		void delay_(unsigned long ms);
		void delayMicroseconds_(unsigned long us);
		void disableSerialReport(void);
		void enableSerialReport(void);
	private:
		bool inited;
};
extern Quirkbot_ Quirkbot;

// Use some macro sorcery to ovewrite Arduino's delays with Quirkbot's safe equivalents
void setup_();
void loop_();
#define setup() setup_()
#define loop() loop_()
#define delay(ms) Quirkbot.delay_(ms)
#define delayMicroseconds(us) Quirkbot.delayMicroseconds_(us)

#endif
