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
    along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HMC6343_H
#define HMC6343_H

//#includes
#include <Arduino.h>
#include <Wire.h>

#define HMC6343_ADDRESS 0x19
#define ACCELEROMETER_REG 0x40
#define MAGNETOMETER_REG 0x45
#define HEADING_REG 0x50
#define TILT_REG 0x55


using namespace std;

class hmc6343 {
	private:
		void readReg(byte register, float& x, float& y, float& z);
			
	public:
		hmc6343();		
		
		void readAcc(float& x, float& y, float& z);
		void readMag(float& x, float& y, float& z);
		void readHeading(float& x, float& y, float& z);
		void readTemp(float& temperature);

			
	
};

#endif	/* COORDINATE_H */

