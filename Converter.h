#ifndef Converter_h_
#define Converter_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "HasIn.h"
#include "HasOut.h"

class Converter :
public Node,
public Contains4Inputs<float, float, float, float>,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	Converter():
	Contains4Inputs<float, float, float, float>
		(inMin, inMax, outMin, outMax),
	HasIn<float>
		(this),
	HasOut<float>
		(this){

		registerInput(inMin);
		registerInput(inMax);
		registerInput(outMin);
		registerInput(outMax);
		
		inMin = 0.0;
		inMax = 1.0;
		outMin = 0.0;
		outMax = 1.0;
	};
	
	Input<float> inMin;
	Input<float> inMax;
	Input<float> outMin;
	Input<float> outMax;

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
				outMin.get(),
				outMax.get()
			)
		);
	}
};

#endif
