#include "NodeStatistics.h"

Statistics::Statistics():
HasOut
	(this){
	registerInput(operation);
	registerInputCollection(items);

	operation = STATISTICS_AVERAGE;
}
Statistics::~Statistics(){}
void Statistics::onInternalInputChange(BaseInput &internalInput){
	if(operation.get() == STATISTICS_AVERAGE) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		out.set(sum / (float)items.collection.size());
		return;
	}

	if(operation.get() == STATISTICS_SUM) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		out.set(sum);
		return;
	}

	if(operation.get() == STATISTICS_MIN) {
		float ref = 3.4028235E+38;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() < ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}

	if(operation.get() == STATISTICS_MAX) {
		float ref = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() > ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}
}
