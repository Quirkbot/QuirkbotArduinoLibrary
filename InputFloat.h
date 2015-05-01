#ifndef InputFloat_h_
#define InputFloat_h_

#include "BaseInput.h"
#include "OutputFloat.h"
class OutputFloat;

class InputFloat : public BaseInput{
	friend class Node;
	public:

	InputFloat();
	~InputFloat();
	
	/**
	 * Handle for primitives connections.
	 **/
	void operator=(const float &value);

	/**
	 * Handle for output connections.
	 **/
	void connect(const OutputFloat &output);

	/**
	 * Remove connections
	 **/
	void disconnect();

	/**
	 * Getter
	 **/	
	float get();

	protected:
	void handleValueConnection(const float &value);
	void handleOutputConnection(const OutputFloat &output);
	void onOutputChange(float value);
	void clearOutput();

	float value;
	OutputFloat * output;
};
#endif