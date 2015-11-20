#ifndef Mathematics_h_
#define Mathematics_h_

#include "CommonNodeIncludes.h"

/**
 * Node with a "in" input and "out" output.
 */
class MathNode:
public Node,
public HasIn,
public HasOut{
	public:
	
	MathNode();
	~MathNode();
};

/**
 * Node with "in" and "operand" inputs and "out" output.
 */
class MathOperationNode:
public MathNode{
	public:
	
	MathOperationNode();
	~MathOperationNode();

	Input operand;
};


/*******************************************************************************
** BASIC MATH ******************************************************************
*******************************************************************************/

/**
 * Computes natural logarithm.
 * If "in" negative, a domain error occurs.
 */
class Logarithm :
public MathNode{
	public:
	Logarithm();
	~Logarithm();
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};
/**
 * Computes common logarithm.
 * If "in" negative, a domain error occurs.
 */
class Logarithm10 :
public MathNode{
	public:
	Logarithm10();
	~Logarithm10();
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes square root.
 * If "in" negative, a domain error occurs.
 */
class SquareRoot : 
public MathNode{
	public:
	SquareRoot();
	~SquareRoot();
	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes absolute value.
 * If "in" negative, a domain error occurs.
 */
class Absolute :
public MathNode{
	public:
	Absolute();
	~Absolute();
	protected:
	void onInternalInputChange(BaseInput &internalInput);
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
	Power();
	~Power();

	Input &exponent;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the sum.
 */
class Addition :
public MathOperationNode{
	public:
	Addition();
	~Addition();

	Input &addend;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the difference.
 */
class Subtraction :
public MathOperationNode{
	public:
	Subtraction();
	~Subtraction();

	Input &subtraend;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the multiplication.
 */
class Multiplication :
public MathOperationNode{
	public:
	Multiplication();
	~Multiplication();

	Input &multiplier;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the division.
 */
class Division :
public MathOperationNode{
	public:
	Division();
	~Division();

	Input &divisor;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the remainder.
 */
class Modulo :
public MathOperationNode{
	public:
	Modulo();
	~Modulo();

	Input &denominator;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the largest.
 */
class Maximum :
public MathOperationNode{
	public:
	Maximum();
	~Maximum();

	Input &alternative;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes the largest.
 */
class Minimum :
public MathOperationNode{
	public:
	Minimum();
	~Minimum();

	Input &alternative;

	protected:
	void onInternalInputChange(BaseInput &internalInput);
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
public MathNode{
	public:
	Ceiling();
	~Ceiling();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Round down value.
 * Rounds the "in" downward so that the "out" will be the largest
 * integral value that is not greater than the "in".
 */
class Floor :
public MathNode{
	public:
	Floor();
	~Floor();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Round to nearest.
 * Rounds the "in" so that the "out" will be the integral value that is
 * nearest to the "in", with halfway cases rounded away from zero.
 */
class Round :
public MathNode{
	public:
	Round();
	~Round();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/*******************************************************************************
** TRIGONOMETRY ****************************************************************
*******************************************************************************/


/**
 * Computes sine.
 * The "in" is an angle (in radians). The "out" will be between -1 and 1.
 */
class Sine :
public MathNode{
	public:
	Sine();
	~Sine();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes arc sine.
 * The "in" is a range (between -1 and 1). The "out" will be an angle
 * (in radians). If "in" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcSine :
public MathNode{
	public:
	ArcSine();
	~ArcSine();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes cosine.
 * The "in" is an angle (in radians). The "out" will be between -1 and 1.
 */
class Cosine :
public MathNode{
	public:
	Cosine();
	~Cosine();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes src cosine.
 * The "in" is a range (between -1 and 1). The "out" will be an angle
 * (in radians). If "in" is out of this interval (between -1 and 1), a domain
 * error occurs.
 */
class ArcCosine :
public MathNode{
	public:
	ArcCosine();
	~ArcCosine();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes tangent.
 * The "in" is an angle (in radians). The "out" will be between negative
 * infinity and infinity.
 */
class Tangent :
public MathNode{
	public:
	Tangent();
	~Tangent();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

/**
 * Computes arc tangent.
 * The "in" is a range. The "out" will be an angle (in radians).
 */
class ArcTangent :
public MathNode{
	public:
	ArcTangent();
	~ArcTangent();
	protected:

	void onInternalInputChange(BaseInput &internalInput);
};

#endif