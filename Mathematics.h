#ifndef Mathematics_h_
#define Mathematics_h_

#include <Arduino.h>

#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "HasIn.h"
#include "HasOut.h"

/**
 * Node with a "in" input and "out" output.
 */
class MathNode:
public Node,
public HasIn<float>,
public HasOut<float>{
	public:
	
	MathNode() :
	HasIn<float>
		(this),
	HasOut<float>
		(this){
	};
};

/**
 * Node with a single "in" input and "out" output.
 */
class MathBasicNode:
public MathNode,
public Contains1Input<float>{
	public:
	
	MathBasicNode() :
	Contains1Input<float>(in)
	{}
};

/**
 * Node with "in" and "operand" inputs and "out" output.
 */
class MathOperationNode:
public MathNode,
public Contains2Inputs<float, float>{
	public:
	
	MathOperationNode() :
	Contains2Inputs<float, float>(in, operand)
	{
		registerInput(operand);
	};

	Input<float> operand;
};


/*******************************************************************************
** BASIC MATH ******************************************************************
*******************************************************************************/

/**
 * Computes natural logarithm.
 * If "in" negative, a domain error occurs.
 */
class Logarithm :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Logarithm::onInternalInputChange(BaseInput &internalInput){
	out.set( log(in.get()) );
};

/**
 * Computes common logarithm.
 * If "in" negative, a domain error occurs.
 */
class Logarithm10 :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Logarithm10::onInternalInputChange(BaseInput &internalInput){
	out.set( log10(in.get()) );
};

/**
 * Computes square root.
 * If "in" negative, a domain error occurs.
 */
class SquareRoot : 
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void SquareRoot::onInternalInputChange(BaseInput &internalInput){
	out.set( sqrt(in.get()) );
};

/**
 * Computes absolute value.
 * If "in" negative, a domain error occurs.
 */
class Absolute :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Absolute::onInternalInputChange(BaseInput &internalInput){
	out.set( fabs(in.get()) );
};


/*******************************************************************************
** OPERATIONS ******************************************************************
*******************************************************************************/

/**
 * Computes absolute value.
 * If "in" negative, a domain error occurs.
 */
class Power :
public MathOperationNode{
	public:
	
	Power():
	exponent(operand)
	{};

	Input<float> &exponent;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Power::onInternalInputChange(BaseInput &internalInput){
	out.set( pow(in.get(), exponent.get()) );
};

/**
 * Computes the sum.
 */
class Addition :
public MathOperationNode{
	public:
	
	Addition():
	addend(operand)
	{};

	Input<float> &addend;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Addition::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() + operand.get() );
};

/**
 * Computes the difference.
 */
class Subtraction :
public MathOperationNode{
	public:
	
	Subtraction():
	subtraend(operand)
	{};

	Input<float> &subtraend;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Subtraction::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() - operand.get() );
};

/**
 * Computes the multiplication.
 */
class Multiplication :
public MathOperationNode{
	public:
	
	Multiplication():
	multiplier(operand)
	{};

	Input<float> &multiplier;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Multiplication::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() * operand.get() );
};

/**
 * Computes the division.
 */
class Division :
public MathOperationNode{
	public:
	
	Division():
	divisor(operand)
	{};

	Input<float> &divisor;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Division::onInternalInputChange(BaseInput &internalInput){
	out.set( in.get() / operand.get() );
};

/**
 * Computes the remainder.
 */
class Modulo :
public MathOperationNode{
	public:
	
	Modulo():
	denominator(operand)
	{};

	Input<float> &denominator;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Modulo::onInternalInputChange(BaseInput &internalInput){
	out.set( fmod(in.get(), operand.get()) );
};

/**
 * Computes the largest.
 */
class Maximum :
public MathOperationNode{
	public:
	
	Maximum():
	alternative(operand)
	{};

	Input<float> &alternative;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Maximum::onInternalInputChange(BaseInput &internalInput){
	out.set( max(in.get(), operand.get()) );
};


/**
 * Computes the largest.
 */
class Minimum :
public MathOperationNode{
	public:
	
	Minimum():
	alternative(operand)
	{};

	Input<float> &alternative;

	protected:
	
	void onInternalInputChange(BaseInput &internalInput);
};
void Minimum::onInternalInputChange(BaseInput &internalInput){
	out.set( min(in.get(), operand.get()) );
};


/*******************************************************************************
** ROUNDING ********************************************************************
*******************************************************************************/

/**
 * Round up value.
 * Rounds the "in" upward so that the "out" will be the smallest
 * integral value that is not less than the "in".
 */
class Ceiling :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Ceiling::onInternalInputChange(BaseInput &internalInput){
	out.set( ceil(in.get()) );
};

/**
 * Round down value.
 * Rounds the "in" downward so that the "out" will be the largest
 * integral value that is not greater than the "in".
 */
class Floor :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Floor::onInternalInputChange(BaseInput &internalInput){
	out.set( floor(in.get()) );
};

/**
 * Round to nearest.
 * Rounds the "in" so that the "out" will be the integral value that is
 * nearest to the "in", with halfway cases rounded away from zero.
 */
class Round :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Round::onInternalInputChange(BaseInput &internalInput){
	out.set( round(in.get()) );
};


/*******************************************************************************
** TRIGONOMETRY ****************************************************************
*******************************************************************************/


/**
 * Computes sine.
 * The "in" is an angle (in radians). The "out" will be between -1 and 1.
 */
class Sine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Sine::onInternalInputChange(BaseInput &internalInput){
	out.set( sin(in.get()) );
};

/**
 * Computes arc sine.
 * The "in" is a range (between -1 and 1). The "out" will be an angle
 * (in radians). If "in" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcSine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void ArcSine::onInternalInputChange(BaseInput &internalInput){
	out.set( asin(in.get()) );
};

/**
 * Computes cosine.
 * The "in" is an angle (in radians). The "out" will be between -1 and 1.
 */
class Cosine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Cosine::onInternalInputChange(BaseInput &internalInput){
	out.set( cos(in.get()) );
};

/**
 * Computes src cosine.
 * The "in" is a range (between -1 and 1). The "out" will be an angle
 * (in radians). If "in" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcCosine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void ArcCosine::onInternalInputChange(BaseInput &internalInput){
	out.set( acos(in.get()) );
};

/**
 * Computes tangent.
 * The "in" is an angle (in radians). The "out" will be between negative
 * infinity and infinity.
 */
class Tangent :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void Tangent::onInternalInputChange(BaseInput &internalInput){
	out.set( tan(in.get()) );
};

/**
 * Computes arc tangent.
 * The "in" is a range. The "out" will be an angle (in radians).
 */
class ArcTangent :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};
void ArcTangent::onInternalInputChange(BaseInput &internalInput){
	out.set( atan(in.get()) );
};

#endif