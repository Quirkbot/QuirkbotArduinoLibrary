#include "Wave.h"
Wave::Wave():
HasInterval
	(this),
HasOut
	(this){
	registerInput(length);
	registerInput(min);
	registerInput(max);
	registerInput(offset);
	registerInput(type);

	position = 0;

	interval = 0.033;
	length = 1.0;
	min = 0;
	max = 1;
	offset = 0.0;
	type = WAVE_SINE;

}
Wave::~Wave(){}

void Wave::onInternalInputChange(BaseInput &internalInput){
	if(&internalInput == &type){
		float t = type.get();

		if (t >= WAVE_RAMP_DOWN){
			table = WAVE_RAMP_DOWN_TABLE;
		}
		else if (t >= WAVE_RAMP_UP){
			table = WAVE_RAMP_UP_TABLE;
		}
		else if (t >= WAVE_PULSE){
			table = WAVE_PULSE_TABLE;
		}
		else if (t >= WAVE_TRIANGLE){
			table = WAVE_TRIANGLE_TABLE;
		}
		else if(t >= WAVE_SQUARE){
			table = WAVE_SQUARE_TABLE;
		}
		else if (t >= WAVE_SINE){
			table = WAVE_SINE_TABLE;
		}
	}
	else if(&internalInput == &length){
		float basePosition = position - offset.get();
		if(basePosition < 0) basePosition += 1;

		float currentTime = fmod(Bot::seconds, length.get());
		if(length.get() == 0){
			adjust = 0;
			return;
		}
		float diff = currentTime/length.get() - basePosition;
		adjust = diff * length.get();
	}
}
void Wave::onInterval(){
	if(length.get() == 0){
		return;
	}
	float timeSeconds = fmod(Bot::seconds -adjust + offset.get() * length.get(), length.get());
	position = timeSeconds / length.get();
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
