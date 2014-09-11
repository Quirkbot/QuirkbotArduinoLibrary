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
		(inMin, inMax, outputMin, outputMax),
	InputOutputStream<float>
		(this){

		registerInput(inMin);
		registerInput(inMax);
		registerInput(outputMin);
		registerInput(outputMax);
		
		inMin = 0.0;
		inMax = 1.0;
		outputMin = 0.0;
		outputMax = 1.0;
	};
	
	Input<float> inMin;
	Input<float> inMax;
	Input<float> outputMin;
	Input<float> outputMax;

	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

void Converter::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		out.set( 
			mapFloat(
				in.get(),
				inMin.get(),
				inMax.get(),
				outputMin.get(),
				outputMax.get()
			)
		);
	}
};

#endif
