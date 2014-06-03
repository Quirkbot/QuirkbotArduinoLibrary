#ifndef Outputable_h_
#define Outputable_h_

#include "events/OutputUpdateEvent.h"
#include "events/ValueEvent.h"

class OutputUpdateEvent;
class Outputable {
	friend class Parameter;

	public:

		Outputable();
		~Outputable();
		float getOutput();
		
	protected:

		void updateOutput(float output);
		
		ValueEvent updated;
		OutputUpdateEvent* outputUpdated;
		float output;
		
};

#endif
