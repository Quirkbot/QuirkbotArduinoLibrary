#ifndef Wave_h_
#define Wave_h_

#include "CommonNodeIncludes.h"

#include "WaveTables.h"

#define	WAVE_SINE 0
#define	WAVE_SQUARE 1
#define	WAVE_TRIANGLE 2
#define	WAVE_PULSE 3
#define	WAVE_RAMP_UP 4
#define	WAVE_RAMP_DOWN 5

/*
Should we have a bunch of different nodes with an specific wave form, instead of
configuring the wave via the 'type' input? We would get longer and more cryptic
node names, but also would remove the type input (removing inputs is always a 
good thig).

SineWave
SquareWave
TriangleWave
PulseWave
RampUpWave
RampDownWave
*/

class Wave :
public Node,
public HasInterval,
public HasOut
{
	public:

	Wave();

	void onInterval();

	Input duration;
	Input min;
	Input max;
	Input offset;
	Input type;

	protected:

	const byte * table;
	
	void onInternalInputChange(BaseInput &internalInput);
	void serialReport();

	float adjust;
	float position;
};
#endif