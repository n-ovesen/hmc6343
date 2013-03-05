#include <Wire.h>
#include <Streaming.h>
#include "hmc6343.h"
 
hmc6343 hmc; 
float x,y,z,heading,roll,pitch,temperature;
 
void setup() {

	Serial.begin(115200);	
}
 
void loop() {

	hmc.readAcc(x,y,z);
	
	Serial << "Accelerometer values: " << endl;
	Serial <<  "x: " << x << " y: " << y << " z: " << z << endl;
	Serial << endl;
	
	hmc.readMag(x,y,z);
	
	Serial << "Magnetometer values: " << endl;
	Serial <<  "x: " << x << " y: " << y << " z: " << z << endl;
	Serial << endl;
	
	hmc.readHeading(heading, roll, pitch);
	
	Serial << "Heading values: " << endl;
	Serial <<  "Heading: " << heading << " Roll: " << roll << " Pitch: " << pitch << endl;
	Serial << endl;
	
	hmc.readTemp(temperature);
	
	Serial << "Temperature: " << temperature << endl;
	Serial << endl;
	
	delay(5000);
}
