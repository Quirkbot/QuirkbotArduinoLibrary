#include "IRProximity.h"

IRProximity::IRProximity():
	HasInterval
		(this),
	HasOut
		(this){
		registerInput(min);
		registerInput(max);

		min = 0;
		max = 1;
		interval = 0.05;

		readingFlag = false;
		readingA = 0;
		readingB = 0;

		readPin = Bot::locationToAnalogPin(QB_IR_PROXIMITY_INPUT_PIN);

		outputPort = portOutputRegister(digitalPinToPort(QB_IR_PROXIMITY_OUTPUT_PIN));
		outputMask = digitalPinToBitMask(QB_IR_PROXIMITY_OUTPUT_PIN);

		pinMode(QB_IR_PROXIMITY_OUTPUT_PIN, OUTPUT);
		pinMode(readPin, INPUT);
};
IRProximity::~IRProximity(){}

void IRProximity::onInterval(){
	readingFlag = !readingFlag;
	if(readingFlag){
		*outputPort |= outputMask;
		readingA = analogRead(readPin);
	}
	else{
		*outputPort &= ~(outputMask);
		readingB = analogRead(readPin);
	}

	if(readingA > readingB){
		filter.push(0);
	}
	else{
		filter.push(abs(readingB-readingA));
	}
	
	out.set(Bot::map(filter.get(), 0, QB_IR_PROXIMITY_MAX, min.get(), max.get()));
}
