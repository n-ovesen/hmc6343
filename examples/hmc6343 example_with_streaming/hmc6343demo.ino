/*
 *	HMC6343 Library for arduino
 *
 *	AUTHOR:	Nikolai Andre Ek Ovesen
 *	EMAIL:	nikolai.ovesen@gmail.com
 *	GIT:	https://github.com/n-ovesen/
 *	Web:	http://nikolaiovesen.com
 *
 *	LICENSING:
 *
 *	HMC6343 – A library to interface an i2c compatible arduino with the HMC6343
 *	Tilt compensated compass.
 *	Copyright © 2013 Nikolai Andre Ek Ovesen
 *	All rights reserved.
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation; either
 *	version 2.1 of the License, or (at your option) any later version.
 *
 *	This library is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *	Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this library. If not, see <http://www.gnu.org/licenses/>.
 */
 
/*
 * NOTICE! This example is for use with the streaming library by Mikal Hart,
 * you can find this example at: http://arduiniana.org/libraries/streaming/
 */ 

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
