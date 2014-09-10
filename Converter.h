#ifndef Converter_h_
#define Converter_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "Streams.h"

class Converter :
public Node,
public Contains4Inputs<float, float, float, float>,
public InputOutputStream<float>
{
	public:
	
	Converter():
	Contains4Inputs<float, float, float, float>
		(inputMin, inputMax, outputMin, outputMax),
	InputOutputStream<float>
		(source, value){
		registerInput(source);
		registerInput(inputMin);
		registerInput(inputMax);
		registerInput(outputMin);
		registerInput(outputMax);
		
		source = 0.0;
		inputMin = 0.0;
		inputMax = 1.0;
		outputMin = 0.0;
		outputMax = 1.0;
	};

	Input<float> source;
	
	Input<float> inputMin;
	Input<float> inputMax;
	Input<float> outputMin;
	Input<float> outputMax;

	Output<float> value;

	protected:

	void onInternalInputChange(BaseInput &input);
};

void Converter::onInternalInputChange(BaseInput &input){
	if(&input == &source){
		value = mapFloat(source.get(), inputMin.get(), inputMax.get(), outputMin.get(), outputMax.get());
	}
};

#endif
