#ifndef NodeWave_h_
#define NodeWave_h_

#include "CommonNodeIncludes.h"

#include "WaveTables.h"

#define	WAVE_SINE 0
#define	WAVE_SQUARE 1
#define	WAVE_TRIANGLE 2
#define	WAVE_PULSE 3
#define	WAVE_RAMP_UP 4
#define	WAVE_RAMP_DOWN 5

class Wave :
public Node,
public HasInterval
{
	public:

	Wave();
	~Wave();

	void onInterval();

	Input length;
	Input min;
	Input max;
	Input offset;
	Input type;

	Output out;

	protected:

	const byte * table;

	void onInternalInputChange(BaseInput &internalInput);

	float adjust;
	float position;
};
#endif
