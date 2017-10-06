#include "Statistics.h"

Statistics::Statistics():
HasOut
	(this){
	registerInput(operation);
	registerInputCollection(items);

	operation = STATISICS_AVERAGE;
}
Statistics::~Statistics(){}
void Statistics::onInternalInputChange(BaseInput &internalInput){
	if(operation.get() == STATISICS_AVERAGE) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		out.set(sum / (float)items.collection.size());
		return;
	}

	if(operation.get() == STATISICS_SUM) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		out.set(sum);
		return;
	}

	if(operation.get() == STATISICS_MIN) {
		float ref = 3.4028235E+38;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() < ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}

	if(operation.get() == STATISICS_MAX) {
		float ref = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() > ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}
}
