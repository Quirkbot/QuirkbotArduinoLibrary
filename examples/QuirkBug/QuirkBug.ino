#include <QuirkBug.h>

#include <Time.h>
#include <AnalogSensor.h>
#include <Logger.h>
//#include <Led.h>




Time time;
Sine sine;
Power power;
Ceiling ceiling;

Addition addition;
Subtraction subtraction;
Multiplication multiplication;
Division division;
Modulo modulo;
//Floor floor;
//Cosine cosine;
//Power power;
//Mapping mapping;
//Led led;

AnalogSensor sensor;

SerialPrint print;

void setup() {	
	


	/*
	sine.base = time.seconds;

	addition.base = sine.result;
	addition.addend = 2;

	subtraction.base = addition.result;
	subtraction.subtraend = 1;

	multiplication.base = subtraction.result;
	multiplication.multiplier = 10;

	division.base = multiplication.result;
	division.divisor = 2;

	ceiling.base = division.result;

	print.base = ceiling.result;*/

	/*sine.input = time.output;

	addition.input = sine.output;
	addition.operand = 2;

	subtraction.input = addition.output;
	subtraction.operand = 1;

	multiplication.input = subtraction.output;
	multiplication.operand = 10;

	division.input = multiplication.output;
	division.operand = 2;

	ceiling.input = division.output;

	print.input = ceiling.output;*/

	/*sine.in0 = time.out0;

	addition.in0 = sine.out0;
	addition.in1 = 2;

	subtraction.in0 = addition.out0;
	subtraction.in1 = 1;

	multiplication.in0 = subtraction.out0;
	multiplication.in1 = 10;

	division.in0 = multiplication.out0;
	division.in1 = 2;

	ceiling.in0 = division.out0;

	print.in0 = ceiling.out0;*/



	/*sine(time.seconds);
	addition(sine.result, 2);
	subtraction(addition.result, 1);
	multiplication(subtraction.result, 10);
	division(multiplication.result, 2);
	ceiling(division.result);
	modulo(ceiling.result, 5);
	print(modulo.result);*/


	/*sine(time);
	addition(sine, 2);
	subtraction(addition, 1);
	multiplication(subtraction, 10);
	division(multiplication, 2);
	ceiling(division);
	modulo(ceiling, 5);
	print(modulo);*/

	

	//mapping.in = sensor.value;
	//mapping.inMinimum = 0.35;
	//mapping.inMaximum = 0.35;

	//led.pin = 11;
	//led.brighteness = mapping.out;
	//led.on();

	//print(time.output);
	
	/*print.input = sine.output;

	sensor.limit = 0.5;

	led.on(sensor.rising);
	led.off(sensor.under)*/

	sensor.pin = A0;
	//sensor.interval = 100;
	print(sensor);

	//print(time);
}

//float i = 0;
void loop() {
	//i+=0.1;
	//print.input = time.output;
	//delay(100);
	//Serial.println(sensor.value);
	//Serial.println(sensor.value);
	//delay(100);
	
}