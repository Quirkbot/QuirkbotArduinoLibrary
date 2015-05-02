#include "Wave.h"
Wave::Wave():
HasInterval
	(this),
HasOut
	(this){
	registerInput(duration);
	registerInput(offset);
	registerInput(type);

	interval = 0.033;

	min = 0;
	max = 1;

	offset = 0.0;
	type = WAVE_SINE;
	duration = 1.0;

	position = 0;
}
Wave::~Wave(){}

void Wave::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &type){
		float t = type.get();
		if(t == WAVE_SQUARE){
			table = WAVE_SQUARE_TABLE;
		}
		else if (t == WAVE_SQUARE){
			table = WAVE_SQUARE_TABLE;
		}
		if (t == WAVE_PULSE){
			table = WAVE_PULSE_TABLE;
		}
		if (t == WAVE_TRIANGLE){
			table = WAVE_TRIANGLE_TABLE;
		}
		if (t == WAVE_RAMP_UP){
			table = WAVE_RAMP_UP_TABLE;
		}
		if (t == WAVE_RAMP_DOWN){
			table = WAVE_RAMP_DOWN_TABLE;
		}
		if (t == WAVE_SINE){
			table = WAVE_SINE_TABLE;
		}
	}
	else if(&internalInput == &duration){
		float basePosition = position - offset.get();
		if(basePosition < 0) basePosition += 1;

		float currentTime = fmod(Bot::seconds, duration.get());
		if(duration.get() == 0){
			adjust = 0;
			return;
		}
		float diff = currentTime/duration.get() - basePosition;
		adjust = diff * duration.get();
	}
}
void Wave::onInterval(){
	if(duration.get() == 0){
		//out.set(0);
		return;
	}
	float timeSeconds = fmod(Bot::seconds -adjust + offset.get() * duration.get(), duration.get());
	position = timeSeconds / duration.get();
	byte index = position * 256.0;
	out.set(
		Bot::map(
			(float)(pgm_read_byte_near(table + index)),
			0.0,
			255.0,
			min.get(),
			max.get()
		)
	);
}
void Wave::serialReport(){
	byte b = (byte)Bot::map(out.get(), min.get(), max.get(), 0, 249);
	Serial.write(b);
}