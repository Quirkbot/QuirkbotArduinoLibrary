#include "NodeStatistics.h"

Statistics::Statistics(){
	registerInput(operation);
	registerInputCollection(items);

	operation = STAT_AVG;
}
Statistics::~Statistics(){}
void Statistics::onInternalInputChange(BaseInput&){
	if(operation.get() == STAT_AVG) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		if (items.collection.size() > 0) {
			out.set(sum / (float)items.collection.size());
		}
		else {
			out.set(sum);
		}
		return;
	}

	if(operation.get() == STAT_SUM) {
		float sum = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			sum += items.collection[i]->get();
		}
		out.set(sum);
		return;
	}

	if(operation.get() == STAT_MIN) {
		float ref = 3.4028235E+38;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() < ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}

	if(operation.get() == STAT_MAX) {
		float ref = 0.0;
		for (unsigned int i = 0; i < items.collection.size(); i++) {
			if (items.collection[i]->get() > ref)
			ref = items.collection[i]->get();
		}
		out.set(ref);
		return;
	}
}
