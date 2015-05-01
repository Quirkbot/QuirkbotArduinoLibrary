#ifndef Event_h_
#define Event_h_

#include "Vector.h"

class InputFloat;

class Event {
	public:

	typedef void (*VoidHandler)();
	typedef void (*TypedHandler)(float value);
	typedef void (InputFloat::*TypedInputHandler)(float value);
	typedef void (InputFloat::*VoidInputHandler)();
	
	void add(VoidHandler handler);
	void remove(VoidHandler handler);

	void add(TypedHandler handler);
	void remove(TypedHandler handler);

	void add(InputFloat* input, TypedInputHandler handler);
	void remove(TypedInputHandler handler);

	void add(InputFloat* input, VoidInputHandler handler);
	void remove(VoidInputHandler handler);
	
	void dispatch(float &value);
	void dispatch();
	
	private:
	int position(VoidHandler handler);
	int position(TypedHandler handler);
	int position(TypedInputHandler handler);
	int position(VoidInputHandler handler);

	Vector<VoidHandler > voidHandlers;
	Vector<TypedHandler > typedHandlers;
	Vector<TypedInputHandler > typedInputHandlers;
	Vector<VoidInputHandler > voidInputHandlers;
	Vector<InputFloat* > typedInputs;
	Vector<InputFloat* > voidInputs;
	
};

#endif