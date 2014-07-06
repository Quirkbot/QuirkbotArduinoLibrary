#include <QuirkBug.h>

// Create the nodes
AnalogSensor sensor;
Led led;
Converter conversion;
Sequence sequence;
Monitor monitor;

void setup() {

	// Attach sensor to pin A0
	sensor.pin = A0;

	// Attach led to pin 5
	led.pin = 5;

	// Connect the conversion to the sensor.
	// It will help us transform the output from the sensor into a range that
	// can be used to trigger the sequence.
	conversion.connect(sensor);

	// Set the conversion values...
	// The first 2 numbers are the minimum & maximum values of the input we are
	// interested in. The last 2 numbers are the minimum & maximum values of the
	// output in which the input will be remaped into.
	// When we use (0, 0.3, 0, 1), it means we will convert a number from
	// 0 ... 0.3 to 0 ... 1. If input is 0.3, output will be 1; if input is
	// 0.15, output will be 0.5; if input is 0, output will be 0, and so on.
	conversion.set(0, 0.3, 0, 1);
	
	// Create a blinking sequence.
	// Stay "on" for a little while...
	sequence.add(1);
	sequence.add(1);
	sequence.add(1);
	sequence.add(1);
	// ... then turn "off" then "on" quickly twice
	sequence.add(0);
	sequence.add(1);
	sequence.add(0);
	sequence.add(1);
	sequence.add(0);

	// Set the sequence duration to half a second
	sequence.duration = 0.5;

	// Connect the sequence trigger to the the conversion.
	// If conversion is 1.0, then sequence will be activated.
	sequence.trigger(conversion);

	// Connect the led to the sequence.
	led.connect(sequence);	

	// Add the sensor and the conversion to the serial monitor
	// for easier debugging.
	monitor.add(sensor);
	monitor.add(conversion);
}