#include "Mathematics.h"

MathNode::MathNode() :
HasIn
	(this),
HasOut
	(this){
};
MathNode::~MathNode(){}

MathOperationNode::MathOperationNode(){
	registerInput(operand);
};
MathOperationNode::~MathOperationNode(){}
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
Power::Power():
exponent(operand)
{};
Power::~Power(){}
void Power::onInternalInputChange(BaseInput &internalInput){
	out.set( pow(in.get(), exponent.get()) );
};

Addition::Addition():
addend(operand)
{};
Addition::~Addition(){}
void Addition::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() + operand.get() );
};

Subtraction::Subtraction():
subtraend(operand)
{};
Subtraction::~Subtraction(){}
void Subtraction::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() - operand.get() );
};

Multiplication::Multiplication():
multiplier(operand)
{};
Multiplication::~Multiplication(){}
void Multiplication::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() * operand.get() );
};

Division::Division():
divisor(operand)
{};
Division::~Division(){}
void Division::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() / operand.get() );
};

Modulo::Modulo():
denominator(operand)
{};
Modulo::~Modulo(){}
void Modulo::onInternalInputChange(BaseInput &internalInput){
	out.set( fmod(in.get(), operand.get()) );
};

Maximum::Maximum():
alternative(operand)
{};
Maximum::~Maximum(){}
void Maximum::onInternalInputChange(BaseInput &internalInput){
	out.set( max(in.get(), operand.get()) );
};

Minimum::Minimum():
alternative(operand)
{};
Minimum::~Minimum(){}
void Minimum::onInternalInputChange(BaseInput &internalInput){
	out.set( min(in.get(), operand.get()) );
};
/*******************************************************************************
** ROUNDING ********************************************************************
*******************************************************************************/
Ceiling::Ceiling(){}
Ceiling::~Ceiling(){}
void Ceiling::onInternalInputChange(BaseInput &internalInput){
	out.set( ceil(in.get()) );
};
Floor::Floor(){}
Floor::~Floor(){}
void Floor::onInternalInputChange(BaseInput &internalInput){
	out.set( floor(in.get()) );
};
Round::Round(){}
Round::~Round(){}
void Round::onInternalInputChange(BaseInput &internalInput){
	out.set( round(in.get()) );
};
/*******************************************************************************
** TRIGONOMETRY ****************************************************************
*******************************************************************************/
Sine::Sine(){}
Sine::~Sine(){}
void Sine::onInternalInputChange(BaseInput &internalInput){
	out.set( sin(in.get()) );
};
ArcSine::ArcSine(){}
ArcSine::~ArcSine(){}
void ArcSine::onInternalInputChange(BaseInput &internalInput){
	out.set( asin(in.get()) );
};
Cosine::Cosine(){}
Cosine::~Cosine(){}
void Cosine::onInternalInputChange(BaseInput &internalInput){
	out.set( cos(in.get()) );
};
ArcCosine::ArcCosine(){}
ArcCosine::~ArcCosine(){}
void ArcCosine::onInternalInputChange(BaseInput &internalInput){
	out.set( acos(in.get()) );
};
Tangent::Tangent(){}
Tangent::~Tangent(){}
void Tangent::onInternalInputChange(BaseInput &internalInput){
	out.set( tan(in.get()) );
};
ArcTangent::ArcTangent(){}
ArcTangent::~ArcTangent(){}
void ArcTangent::onInternalInputChange(BaseInput &internalInput){
	out.set( atan(in.get()) );
};