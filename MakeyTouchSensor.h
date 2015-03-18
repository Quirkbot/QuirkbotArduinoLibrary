#ifndef MakeyTouchSensor_h_
#define MakeyTouchSensor_h_

#include "CommonNodeIncludes.h"

#define QB_MAX_MAKEY_SENSORS 5

class MakeyTouchSensor :
public Node,
public Updatable,
public HasOut<float>
{
	public:
	
	MakeyTouchSensor():
	HasOut<float>
		(this){
		registerInput(place);
		
		place = -1;

		filter.alpha = 0.8;
	};

	Input<float> place;

	void update();

	protected:	

	void onInternalInputChange(BaseInput &internalInput);

	LowPassFilter filter;

	unsigned int frontPin;
	unsigned int backPin;
	unsigned int tickA;
	unsigned int tickB;


};

void MakeyTouchSensor::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &place) {
		int location = place.get();

		backPin = Bot::locationToBackPin(location);
		frontPin = Bot::locationToFrontPin(location);

		if(backPin == NO_LOCATION) return;

		pinMode(backPin, OUTPUT);
		digitalWrite(backPin, HIGH);

		switch(location){
			case H:
				tickA = 0;
				break;
			case LA:
				tickA = 1;
				break;
			case LL:
				tickA = 2;
				break;
			case RL:
				tickA = 3;
				break;
			case RA:
				tickA = 4;
				break;
		}

		tickB = tickA + 2;

		if(tickB > (QB_MAX_MAKEY_SENSORS-1) ){
			tickB -= QB_MAX_MAKEY_SENSORS;
		}
	}
};

void MakeyTouchSensor::update(){
	if(frontPin == NO_LOCATION) return;

	int tick = Bot::frames % QB_MAX_MAKEY_SENSORS;
	if( tick == tickB){
		pinMode(frontPin, INPUT);
	}
	else if( tick == tickA){
		int reading = digitalRead(frontPin);
		pinMode(frontPin, OUTPUT);
		digitalWrite(frontPin, LOW);

		filter.push(reading);

		if(filter.get() > 0.99) out.set(1);
		else  out.set(0);
	}

}

#endif
