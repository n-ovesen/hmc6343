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

#include <hmc6343.h>
#include <Wire.h>

hmc6343 hmc;										//Creates an instance of the hmc6343 class called hmc

float x,y,z,heading,roll,pitch,temperature;			//Variables to store values returned from the HMC6343 library
 
void setup() {
	Serial.begin(115200);	
	
}
 
void loop() {

	hmc.readAcc(x,y,z);								//Library returns accelerometer values to variable x, y and z.
	
	Serial.println("Accelerometer values: ");		
	Serial.print("x: ");
	Serial.print(x);
	Serial.print(" y: ");
	Serial.print(y);
	Serial.print(" z: ");
	Serial.print(z);
	Serial.println("\n");
	
	hmc.readMag(x,y,z);								//Library returns magnetometer values to variable x, y and z.
	
	Serial.println("Magnetometer values: ");
	Serial.print("x: ");
	Serial.print(x);
	Serial.print(" y: ");
	Serial.print(y);
	Serial.print(" z: ");
	Serial.print(z);
	Serial.println("\n");
	
	hmc.readHeading(heading, roll, pitch);			//Library returns Heading, Roll and Pitch to variable heading, roll and pitch.
	
	Serial.println("Heading values: ");
	Serial.print("Heading: ");
	Serial.print(heading);
	Serial.print(" Roll: ");
	Serial.print(roll);
	Serial.print(" Pitch: ");
	Serial.print(pitch);
	Serial.println("\n");
	
	hmc.readTemp(temperature);						//Library returns temperature to the temperature variable
	
	Serial.print("Temperature: ");
	Serial.print(temperature);
	Serial.println("\n");
	
	delay(1000);									//Waits one second
}
