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

		readingFlag = false;
		readingA = 0;
		readingB = 0;

		outputPort = portOutputRegister(digitalPinToPort(QB_IR_PROXIMITY_OUTPUT_PIN));
		outputMask = digitalPinToBitMask(QB_IR_PROXIMITY_OUTPUT_PIN);

		pinMode(QB_IR_PROXIMITY_OUTPUT_PIN, OUTPUT);
		pinMode(QB_IR_PROXIMITY_INPUT_PIN, INPUT);
};
IRProximity::~IRProximity(){}

void IRProximity::onInterval(){
	readingFlag = !readingFlag;
	if(readingFlag){
		*outputPort |= outputMask;
		readingA = analogRead(QB_IR_PROXIMITY_INPUT_PIN);
	}
	else{
		*outputPort &= ~(outputMask);
		readingB = analogRead(QB_IR_PROXIMITY_INPUT_PIN);
	}

	filter.push(abs(readingA-readingB));
	out.set(Bot::map(filter.get(), 0, QB_IR_PROXIMITY_MAX, min.get(), max.get()));
}
