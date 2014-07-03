#ifndef Buzzer_h_
#define Buzzer_h_

#include "Arduino.h"

#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Streams.h"

class Buzzer:
public Node,
public InputStream<float>{
	public:
	
	Buzzer():
	InputStream<float>
		(tone){

		registerInput(pin);
		registerInput(tone);

		lastFrequency = 0;
		tone = 0;
	};

	void process();

	Input<int> pin;
	Input<float> tone;

	static float calculateTone(float frequency);
	static float MAX_FREQUENCY;

	protected:

	void onInternalInputChange(BaseInput &input);

	int lastFrequency;
};
float Buzzer::MAX_FREQUENCY = 4978.0;
float Buzzer::calculateTone(float frequency){
	return sqrt(frequency / MAX_FREQUENCY);
}
void Buzzer::onInternalInputChange(BaseInput &input){
	if(&input == &pin){
		pinMode(pin, OUTPUT);
		process();
	}
	else if(&input == &tone){
		process();
	}
}
void Buzzer::process(){
	int frequency = (tone * tone) * MAX_FREQUENCY;
	if(lastFrequency == frequency) return;
	lastFrequency = frequency;
	if(frequency != 0) {
		::tone(4, frequency);
	}
	else{
		noTone(pin);
	}
}

/**
Notes generated via JavaScript:
-------------------------------
var freq = {'NOTE_B0':31,'NOTE_C1':33,'NOTE_CS1':35,'NOTE_D1':37,'NOTE_DS1':39,
'NOTE_E1':41,'NOTE_F1':44,'NOTE_FS1':46,'NOTE_G1':49,'NOTE_GS1':52,'NOTE_A1':55,
'NOTE_AS1':58,'NOTE_B1':62,'NOTE_C2':65,'NOTE_CS2':69,'NOTE_D2':73,
'NOTE_DS2':78,'NOTE_E2':82,'NOTE_F2':87,'NOTE_FS2':93,'NOTE_G2':98,
'NOTE_GS2':104,'NOTE_A2':110,'NOTE_AS2':117,'NOTE_B2':123,'NOTE_C3':131,
'NOTE_CS3':139,'NOTE_D3':147,'NOTE_DS3':156,'NOTE_E3':165,'NOTE_F3':175,
'NOTE_FS3':185,'NOTE_G3':196,'NOTE_GS3':208,'NOTE_A3':220,'NOTE_AS3':233,
'NOTE_B3':247,'NOTE_C4':262,'NOTE_CS4':277,'NOTE_D4':294,'NOTE_DS4':311,
'NOTE_E4':330,'NOTE_F4':349,'NOTE_FS4':370,'NOTE_G4':392,'NOTE_GS4':415,
'NOTE_A4':440,'NOTE_AS4':466,'NOTE_B4':494,'NOTE_C5':523,'NOTE_CS5':554,
'NOTE_D5':587,'NOTE_DS5':622,'NOTE_E5':659,'NOTE_F5':698,'NOTE_FS5':740,
'NOTE_G5':784,'NOTE_GS5':831,'NOTE_A5':880,'NOTE_AS5':932,'NOTE_B5':988,
'NOTE_C6':1047,'NOTE_CS6':1109,'NOTE_D6':1175,'NOTE_DS6':1245,'NOTE_E6':1319,
'NOTE_F6':1397,'NOTE_FS6':1480,'NOTE_G6':1568,'NOTE_GS6':1661,'NOTE_A6':1760,
'NOTE_AS6':1865,'NOTE_B6':1976,'NOTE_C7':2093,'NOTE_CS7':2217,'NOTE_D7':2349,
'NOTE_DS7':2489,'NOTE_E7':2637,'NOTE_F7':2794,'NOTE_FS7':2960,'NOTE_G7':3136,
'NOTE_GS7':3322,'NOTE_A7':3520,'NOTE_AS7':3729,'NOTE_B7':3951,'NOTE_C8':4186,
'NOTE_CS8':4435,'NOTE_D8':4699,'NOTE_DS8':4978};
var s = '';
for(var note in freq){
	s += "#define " + note + ' ';
	s += Math.sqrt(freq[note]/4978);
	s += "\n";
}
console.log(s);
**/	
#define NO_NOTE		0.0
#define NOTE_B0		0.07891388f
#define NOTE_C1		0.08141970f
#define NOTE_CS1	0.08385067f
#define NOTE_D1		0.08621313f
#define NOTE_DS1	0.08851255f
#define NOTE_E1		0.09075372f
#define NOTE_F1		0.09401537f
#define NOTE_FS1	0.09612834f
#define NOTE_G1		0.09921345f
#define NOTE_GS1	0.10220549f
#define NOTE_A1		0.10511238f
#define NOTE_AS1	0.10794102f
#define NOTE_B1		0.11160108f
#define NOTE_C2		0.11426921f
#define NOTE_CS2	0.11773269f
#define NOTE_D2		0.12109716f
#define NOTE_DS2	0.12517564f
#define NOTE_E2		0.12834515f
#define NOTE_F2		0.13220022f
#define NOTE_FS2	0.13668285f
#define NOTE_G2		0.14030902f
#define NOTE_GS2	0.14454039f
#define NOTE_A2		0.14865136f
#define NOTE_AS2	0.15330823f
#define NOTE_B2		0.15719007f
#define NOTE_C3		0.16222142f
#define NOTE_CS3	0.16710134f
#define NOTE_D3		0.17184275f
#define NOTE_DS3	0.17702510f
#define NOTE_E3		0.18205999f
#define NOTE_F3		0.18749581f
#define NOTE_FS3	0.19277842f
#define NOTE_G3		0.19842691f
#define NOTE_GS3	0.20441098f
#define NOTE_A3		0.21022477f
#define NOTE_AS3	0.21634681f
#define NOTE_B3		0.22275170f
#define NOTE_C4		0.22941573f
#define NOTE_CS4	0.23589157f
#define NOTE_D4		0.24302235f
#define NOTE_DS4	0.24994977f
#define NOTE_E4		0.25747171f
#define NOTE_F4		0.26478005f
#define NOTE_FS4	0.27262985f
#define NOTE_G4		0.28061804f
#define NOTE_GS4	0.28873311f
#define NOTE_A4		0.29730272f
#define NOTE_AS4	0.30596060f
#define NOTE_B4		0.31501847f
#define NOTE_C5		0.32413311f
#define NOTE_CS5	0.33360107f
#define NOTE_D5		0.34339313f
#define NOTE_DS5	0.35348236f
#define NOTE_E5		0.36384403f
#define NOTE_F5		0.37445554f
#define NOTE_FS5	0.38555684f
#define NOTE_G5		0.39685383f
#define NOTE_GS5	0.40857620f
#define NOTE_A5		0.42044954f
#define NOTE_AS5	0.43269363f
#define NOTE_B5		0.44550340f
#define NOTE_C6		0.45861250f
#define NOTE_CS6	0.47199600f
#define NOTE_D6		0.48583800f
#define NOTE_DS6	0.50010043f
#define NOTE_E6		0.51474833f
#define NOTE_F6		0.52974974f
#define NOTE_FS6	0.54525971f
#define NOTE_G6		0.56123608f
#define NOTE_GS6	0.57764014f
#define NOTE_A6		0.59460545f
#define NOTE_AS6	0.61208533f
#define NOTE_B6		0.63003695f
#define NOTE_C7		0.64842114f
#define NOTE_CS7	0.66735266f
#define NOTE_D7		0.68693249f
#define NOTE_DS7	0.70710678f
#define NOTE_E7		0.72782608f
#define NOTE_F7		0.74917927f
#define NOTE_FS7	0.77111368f
#define NOTE_G7		0.79370767f
#define NOTE_GS7	0.81690653f
#define NOTE_A7		0.84089909f
#define NOTE_AS7	0.86550333f
#define NOTE_B7		0.89089407f
#define NOTE_C8		0.91700597f
#define NOTE_CS8	0.94388561f
#define NOTE_D8		0.97157264f
#define NOTE_DS8 	1.0

#endif