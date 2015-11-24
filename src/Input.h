#ifndef Input_h_
#define Input_h_

#include "BaseInput.h"
#include "Output.h"
class Output;

class Input : public BaseInput{
	friend class Node;
	public:

	Input();
	~Input();

	/**
	 * Handle for primitives connections.
	 **/
	void operator=(const float &value);

	/**
	 * Handle for output connections.
	 **/
	void connect(const Output &output);

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
	void handleOutputConnection(const Output &output);
	void onOutputChange(float value);
	void clearOutput();

	float value;
	Output * output;
};
#endif
