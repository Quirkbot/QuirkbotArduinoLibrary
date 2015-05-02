#include "Mathematics.h"

MathNode::MathNode() :
HasIn
	(this),
HasOut
	(this){
};

MathOperationNode::MathOperationNode(){
	registerInput(operand);
};
/*******************************************************************************
** BASIC MATH ******************************************************************
*******************************************************************************/
Logarithm::Logarithm(){}
Logarithm::~Logarithm(){}
void Logarithm::onInternalInputChange(BaseInput &internalInput){
	out.set( log(in.get()) );
};
Logarithm10::Logarithm10(){}
Logarithm10::~Logarithm10(){}
void Logarithm10::onInternalInputChange(BaseInput &internalInput){
	out.set( log10(in.get()) );
};
SquareRoot::SquareRoot(){}
SquareRoot::~SquareRoot(){}
void SquareRoot::onInternalInputChange(BaseInput &internalInput){
	out.set( sqrt(in.get()) );
};
Absolute::Absolute(){}
Absolute::~Absolute(){}
void Absolute::onInternalInputChange(BaseInput &internalInput){
	out.set( fabs(in.get()) );
};
/*******************************************************************************
** OPERATIONS ******************************************************************
*******************************************************************************/
void Power::onInternalInputChange(BaseInput &internalInput){
	out.set( pow(in.get(), exponent.get()) );
};
void Addition::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() + operand.get() );
};
void Subtraction::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() - operand.get() );
};
void Multiplication::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() * operand.get() );
};
void Division::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() / operand.get() );
};
void Modulo::onInternalInputChange(BaseInput &internalInput){
	out.set( fmod(in.get(), operand.get()) );
};
void Maximum::onInternalInputChange(BaseInput &internalInput){
	out.set( max(in.get(), operand.get()) );
};
void Minimum::onInternalInputChange(BaseInput &internalInput){
	out.set( min(in.get(), operand.get()) );
};
/*******************************************************************************
** ROUNDING ********************************************************************
*******************************************************************************/
void Ceiling::onInternalInputChange(BaseInput &internalInput){
	out.set( ceil(in.get()) );
};
void Floor::onInternalInputChange(BaseInput &internalInput){
	out.set( floor(in.get()) );
};
void Round::onInternalInputChange(BaseInput &internalInput){
	out.set( round(in.get()) );
};
/*******************************************************************************
** TRIGONOMETRY ****************************************************************
*******************************************************************************/
void Sine::onInternalInputChange(BaseInput &internalInput){
	out.set( sin(in.get()) );
};
void ArcSine::onInternalInputChange(BaseInput &internalInput){
	out.set( asin(in.get()) );
};
void Cosine::onInternalInputChange(BaseInput &internalInput){
	out.set( cos(in.get()) );
};
void ArcCosine::onInternalInputChange(BaseInput &internalInput){
	out.set( acos(in.get()) );
};
void Tangent::onInternalInputChange(BaseInput &internalInput){
	out.set( tan(in.get()) );
};
void ArcTangent::onInternalInputChange(BaseInput &internalInput){
	out.set( atan(in.get()) );
};