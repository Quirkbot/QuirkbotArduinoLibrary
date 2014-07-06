#include <QuirkBug.h>

Servo servo;
Led led;
Buzzer buzzer;
Sonar sonar;

Wave wave;
Converter converter;
Converter sonarConverter;
Gate gate;

Wave communicationWave;
List communicationOutput;

Wave buzzerWave;
List buzzerOutput;

Monitor monitor;


void setup() {
 
  wave.duration = 5;
   
  converter.set(0, 1, 0.4, 0.8);
  converter.connect(wave);
  
  sonar.pin = 7;
  sonarConverter.set(0.3, 0.5, 1, 0);
  sonarConverter.connect(sonar);
  
  gate.connect(converter);
  gate.invert = true;
  gate.trigger(sonarConverter);
  
  servo.pin = 3;       
  servo.connect(gate);
  
  communicationWave.duration = 0.5;
  communicationOutput.add(0);
  communicationOutput.add(communicationWave);
  communicationOutput.connect(sonarConverter);
  
  led.pin = 5;
  led.connect(communicationOutput);
  
  buzzer.pin = 4;
  buzzer.connect(communicationOutput);
  
 

}