/*
HMC6343 – A small library for Arduino to interface with the HMC6343 tilt compensated compass.
Copyright © 2013 Nikolai Andre Ek Ovesen
All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "hmc6343.h"

hmc6343::hmc6343(){
	Wire.begin();
}

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

void hmc6343::readAcc(float& x, float& y, float& z){

	float roll, pitch, yaw;
	hmc6343::readReg(ACCELEROMETER_REG, roll, pitch, yaw);
	x = roll / 10;
	y = pitch / 10;
	z = yaw / 10;
	return;	
}

void hmc6343::readMag(float& x, float& y, float& z){

	float magX, magY, magZ;
	hmc6343::readReg(MAGNETOMETER_REG, magX, magY, magZ);
	x = magX / 10;
	y = magY / 10;
	z = magZ / 10;
	return;	
}

void hmc6343::readHeading(float& x, float& y, float& z) {

	float h, p, r;
	hmc6343::readReg(HEADING_REG, h, p, r);
	x = h / 10;
	y = p / 10;
	z = r / 10;
	return;
}

void hmc6343::readTemp(float& temperature){

	float t, p, r;
	hmc6343::readReg(TILT_REG, r, p, t);
	temperature = t / 10;
	return;
}
