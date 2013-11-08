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

#ifndef HMC6343_H
#define HMC6343_H

#include <Arduino.h>
#include <Wire.h>

//Defines the addresses for the various registers on the HMC6343

#define HMC6343_ADDRESS 0x19		//Address of the hmc6343 itself
#define ACCELEROMETER_REG 0x40		//Accelerometer
#define MAGNETOMETER_REG 0x45		//Magnetometer
#define HEADING_REG 0x50			//Heading
#define TEMP_REG 0x55				//Temperature

using namespace std;

//Class and function prototypes

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

