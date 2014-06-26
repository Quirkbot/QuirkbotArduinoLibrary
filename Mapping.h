#ifndef Mapping_h_
#define Mapping_h_

#include "Arduino.h"

#include "Node.h"
#include "Input.h"
#include "Output.h"


class Mapping : public Node{
	public:
	
	Mapping();

	Input<float> in;
	Input<float> inMinimum;
	Input<float> inMaximum;
	Input<float> outMinimum;
	Input<float> outMaximum;
	Output<float> out;

	static float mapFloat(float x, float inMin, float inMax, float outMin, float outMax);

	protected:

	void onInternalInputChange(BaseInput &input);
};

#endif
