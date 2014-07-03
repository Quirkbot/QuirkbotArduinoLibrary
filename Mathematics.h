#ifndef Mathematics_h_
#define Mathematics_h_

#include <Arduino.h>

#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "ContainsInputs.h"
#include "Streams.h"

/**
 * Node with a "base" input and "result" output.
 */
class MathNode:
public Node,
public InputOutputStream<float>{
	public:
	
	MathNode() :
	InputOutputStream<float>(base, result){
		registerInput(base);
	};

	Input<float> base;
	Output<float> result;
};

/**
 * Node with a single "base" input and "result" output.
 */
class MathBasicNode:
public MathNode,
public Contains1Input<float>{
	public:
	
	MathBasicNode() :
	Contains1Input<float>(base)
	{}
};

/**
 * Node with "base" and "operand" inputs and "result" output.
 */
class MathOperationNode:
public MathNode,
public Contains2Inputs<float, float>{
	public:
	
	MathOperationNode() :
	Contains2Inputs<float, float>(base, operand)
	{
		registerInput(operand);
	};

	Input<float> operand;
};


/*******************************************************************************
** BASIC MATH ******************************************************************
*******************************************************************************/

/**
 * Compute natural logarithm.
 * If "base" negative, a domain error occurs.
 */
class Logarithm :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Logarithm::onInternalInputChange(BaseInput &input){
	result = logf(base);
};
typedef Logarithm Log;

/**
 * Compute common logarithm.
 * If "base" negative, a domain error occurs.
 */
class Logarithm10 :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Logarithm10::onInternalInputChange(BaseInput &input){
	result = log10(base);
};
typedef Logarithm10 Log10;

/**
 * Compute square root.
 * If "base" negative, a domain error occurs.
 */
class SquareRoot : 
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void SquareRoot::onInternalInputChange(BaseInput &input){
	result = sqrtf(base);
};
typedef SquareRoot Sqrt;

/**
 * Compute absolute value.
 * If "base" negative, a domain error occurs.
 */
class Absolute :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Absolute::onInternalInputChange(BaseInput &input){
	result = fabs(base);
};
typedef Absolute Abs;

/**
 * Compute absolute value.
 * If "base" negative, a domain error occurs.
 */
class Power :
public MathOperationNode{
	public:
	
	Power():
	exponent(operand)
	{};

	Input<float> &exponent;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Power::onInternalInputChange(BaseInput &input){
	result = powf(base, exponent);
};
typedef Power Pow;

/*******************************************************************************
** OPERATIONS ******************************************************************
*******************************************************************************/

/**
 * Compute the sum.
 */
class Addition :
public MathOperationNode{
	public:
	
	Addition():
	addend(operand)
	{};

	Input<float> &addend;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Addition::onInternalInputChange(BaseInput &input){
	result = base + operand;
};
typedef Addition Add;

/**
 * Compute the difference.
 */
class Subtraction :
public MathOperationNode{
	public:
	
	Subtraction():
	subtraend(operand)
	{};

	Input<float> &subtraend;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Subtraction::onInternalInputChange(BaseInput &input){
	result = base - operand;
};
typedef Subtraction Remove;

/**
 * Compute the multiplication.
 */
class Multiplication :
public MathOperationNode{
	public:
	
	Multiplication():
	multiplier(operand)
	{};

	Input<float> &multiplier;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Multiplication::onInternalInputChange(BaseInput &input){
	result = base * operand;
};
typedef Multiplication Mult;

/**
 * Compute the division.
 */
class Division :
public MathOperationNode{
	public:
	
	Division():
	divisor(operand)
	{};

	Input<float> &divisor;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Division::onInternalInputChange(BaseInput &input){
	result = base / operand;
};
typedef Division Div;

/**
 * Compute the remainder.
 */
class Modulo :
public MathOperationNode{
	public:
	
	Modulo():
	denominator(operand)
	{};

	Input<float> &denominator;

	protected:
	
	void onInternalInputChange(BaseInput &input);
};
void Modulo::onInternalInputChange(BaseInput &input){
	result = fmod(base,operand);
};
typedef Modulo mod;


/*******************************************************************************
** ROUNDING ********************************************************************
*******************************************************************************/

/**
 * Round up value.
 * Rounds the "base" upward so that the "result" will be the smallest
 * integral value that is not less than the "base".
 */
class Ceiling :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Ceiling::onInternalInputChange(BaseInput &input){
	result = ceilf(base);
};
typedef Ceiling Ceil;

/**
 * Round down value.
 * Rounds the "base" downward so that the "result" will be the largest
 * integral value that is not greater than the "base".
 */
class Floor :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Floor::onInternalInputChange(BaseInput &input){
	result = floorf(base);
};

/**
 * Round to nearest.
 * Rounds the "base" so that the "result" will be the integral value that is
 * nearest to the "base", with halfway cases rounded away from zero.
 */
class Round :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Round::onInternalInputChange(BaseInput &input){
	result = roundf(base);
};


/*******************************************************************************
** TRIGONOMETRY ****************************************************************
*******************************************************************************/


/**
 * Compute sine.
 * The "base" is an angle (in radians). The "result" will be between -1 and 1.
 */
class Sine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Sine::onInternalInputChange(BaseInput &input){
	result = sinf(base);
};
typedef Sine Sin;

/**
 * Compute arc sine.
 * The "base" is a range (between -1 and 1). The "result" will be an angle
 * (in radians). If "base" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcSine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void ArcSine::onInternalInputChange(BaseInput &input){
	result = asinf(base);
};
typedef ArcSine Asin;

/**
 * Compute cosine.
 * The "base" is an angle (in radians). The "result" will be between -1 and 1.
 */
class Cosine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Cosine::onInternalInputChange(BaseInput &input){
	result = cosf(base);
};
typedef Cosine Cos;

/**
 * Compute src cosine.
 * The "base" is a range (between -1 and 1). The "result" will be an angle
 * (in radians). If "base" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcCosine :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void ArcCosine::onInternalInputChange(BaseInput &input){
	result = acosf(base);
};
typedef ArcCosine Acos;

/**
 * Compute tangent.
 * The "base" is an angle (in radians). The "result" will be between negative
 * infinity and infinity.
 */
class Tangent :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void Tangent::onInternalInputChange(BaseInput &input){
	result = tanf(base);
};
typedef Tangent Tan;

/**
 * Compute arc tangent.
 * The "base" is a range. The "result" will be an angle (in radians).
 */
class ArcTangent :
public MathBasicNode{
	protected:

	void onInternalInputChange(BaseInput &input);
};
void ArcTangent::onInternalInputChange(BaseInput &input){
	result = atanf(base);
};
typedef ArcTangent Atan;

#endif