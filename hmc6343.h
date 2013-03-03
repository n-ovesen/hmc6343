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

