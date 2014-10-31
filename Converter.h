#ifndef Converter_h_
#define Converter_h_

#include "CommonNodeIncludes.h"

class Converter :
public Node,
public HasIn<float>,
public HasOut<float>
{
	public:
	
	Converter():
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

	static float mapFloat(float x, float inMin, float inMax, float outMin, float outMax){
		float result = ((x - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin;
		if(outMin < outMax){
			if(result < outMin) result = outMin;
			else if(result > outMax) result = outMax;
		}
		else{
			if(result > outMin) result = outMin;
			else if(result < outMax) result = outMax;
		}
		
		return result;
	}

	void onInternalInputChange(BaseInput &internalInput);
};

void Converter::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &in){
		out.set( 
			Converter::mapFloat(
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
