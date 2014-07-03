#include <QuirkBug.h>

// Create the nodes
AnalogSensor sensor;
Range range;
Sequence sequence;
Led led;
Monitor monitor;

void setup() {

	// Attach sensor to pin A0
	sensor.pin = A0;

	// Attach LED to pin 5
	led.pin = 5;

	// Connect the range to the sensor
	range.connect(sensor);

	// Set the range "max" to 0.3 so that values in the
	// range "0"..."0.3" will be converted to "0"..."1.0"
	range.max = 0.3;
	
	// Create a blinking sequence:
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
	sequence.duration = 500;

	// Connect the sequence trigger to the the range.
	// If range is 1.0, then sequence will be activated.
	sequence.trigger.connect(range);

	// Connect the led to the sequence.
	led.connect(sequence);	

	// Add the sensor and the range to the serial monitor for easier debugging.
	monitor.add(sensor);
	monitor.add(range);
}