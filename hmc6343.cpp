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

#include "hmc6343.h"

hmc6343::hmc6343(){

	Wire.begin();
}

/**
 * 	@function: private readReg()
 * 
 *	Polls the appropiate register, processes returned data and returns them to
 *	the appropiate function by reference.
 * 
 *	@param byte readReg  -       The register on the HMC6343 to be polled
 * 	@param float& a      -       first value returned from the HMC
 * 	@param float& b      -       second value returned from the HMC
 * 	@param float& c      -       third value returned from the HMC
 * 	@return              -       Returns a, b and c by passing them as a reference.
 */

void hmc6343::readReg(byte reg, float& a, float& b, float& c){

	byte highByte, lowByte;
	Wire.beginTransmission(HMC6343_ADDRESS);   
	Wire.write(reg);             
	Wire.endTransmission();

	Wire.requestFrom(HMC6343_ADDRESS, 6);    
	while(Wire.available() < 1);             

	highByte = Wire.read();              
	lowByte = Wire.read();
	a = ((highByte << 8) + lowByte); 

	highByte = Wire.read();
	lowByte = Wire.read();
	b = ((highByte << 8) + lowByte); 

	highByte = Wire.read();
	lowByte = Wire.read();
	c = ((highByte << 8) + lowByte); 
	return;
}

/**
 * 	@function: readAcc
 * 
 *	Used to return accelerometer values from the HMC6343.
 * 
 * 	@param float& x      -       x axis value returned from the HMC
 * 	@param float& y      -       y axis value returned from the HMC
 * 	@param float& z      -       z axis value returned from the HMC
 * 	@return              -       Returns x, y and z by passing them as a reference
 *								 to the appropiate functions within the sketch
 */

void hmc6343::readAcc(float& x, float& y, float& z){

	float roll, pitch, yaw;
	hmc6343::readReg(ACCELEROMETER_REG, roll, pitch, yaw);
	x = roll / 10;
	y = pitch / 10;
	z = yaw / 10;
	return;	
}

/**
 * 	@function: readMag
 * 
 *	Used to return magnetometer values from the HMC6343.
 * 
 * 	@param float& x      -       x axis value returned from the HMC
 * 	@param float& y      -       y axis value returned from the HMC
 * 	@param float& z      -       z axis value returned from the HMC
 * 	@return              -       Returns x, y and z by passing them as a reference
 *								 to the appropiate functions within the sketch
 */

void hmc6343::readMag(float& x, float& y, float& z){

	float magX, magY, magZ;
	hmc6343::readReg(MAGNETOMETER_REG, magX, magY, magZ);
	x = magX / 10;
	y = magY / 10;
	z = magZ / 10;
	return;	
}

/**
 * 	@function: readHeading
 * 
 *	Used to return calculated value of heading, pitch and roll from the HMC6343
 * 
 * 	@param float& h      -		 tilt compensated heading returned from the HMC
 * 	@param float& p      - 	     pitch returned from the HMC
 * 	@param float& r      -       roll returned from the HMC
 * 	@return              -       Returns h, p and r by passing them as a reference
 *								 to the appropiate functions within the sketch
 */

void hmc6343::readHeading(float& x, float& y, float& z) {

	float h, p, r;
	hmc6343::readReg(HEADING_REG, h, p, r);
	x = h / 10;
	y = p / 10;
	z = r / 10;
	return;
}

/**
 * 	@function: readTemp
 * 
 *	Used to get the temperature from the internal temperature sensor in the HMC6343
 * 
 * 	@param float& temperature		-       Temperature returned from the HMC
 * 	@return              			-       Returns temperature by passing it as a reference
 *			                        	    to the appropiate functions within the sketch
 *	Notice: by adding pitch and roll as parameters to pass by reference you can also get
 *  roll and pitch with this function
 */

void hmc6343::readTemp(float& temperature){

	float t, p, r;
	hmc6343::readReg(TEMP_REG, r, p, t);
	temperature = t / 10;
	return;
}
