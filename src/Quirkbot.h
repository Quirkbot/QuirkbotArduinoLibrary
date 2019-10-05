#ifndef Quirkbot_h_
#define Quirkbot_h_

#include "Arduino.h"

// Easing
#include "Easing.h"

// Inputs
#include "NodeAnalogSensor.h"
#include "NodeDigitalSensor.h"
#include "NodeCircuitTouch.h"
#include "NodeSqueezeSensor.h"
#include "NodeIRProximity.h"
#include "NodeLightSensor.h"
#include "NodeSonar.h"

// Brains
#include "NodeConverter.h"
#include "NodeComparison.h"
#include "NodeConstrain.h"
#include "NodeCounter.h"
#include "NodeGate.h"
#include "NodeList.h"
#include "NodeLogic.h"
#include "NodeMath.h"
#include "NodeRandomizer.h"
#include "NodeSequence.h"
#include "NodeStatistics.h"
#include "NodeWave.h"

// Outputs
#include "NodeLed.h"
#include "NodeDualColorLed.h"
#include "NodeServoMotor.h"
#include "NodeContinuousServo.h"
#include "NodeBuzzer.h"
#include "NodeRGBLed.h"
#include "NodeKeyPress.h"
#include "NodeKeySequence.h"
#include "NodeVoltageOutput.h"

// Debug
#include "NodeSystemMemory.h"
#include "NodeSerialMonitor.h"
#include "NodeTime.h"

class Quirkbot_{
	public:
		Quirkbot_();
		void setup_(void);
		void afterSetup_(void);
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
