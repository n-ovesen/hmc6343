
#include "hmc6343.h"

hmc6343::hmc6343(){
	Wire.begin();
}

void hmc6343::readReg(byte reg, float& a, float& b, float& c){

	byte highByte, lowByte;
	Wire.beginTransmission(HMC6343_ADDRESS);    // Start communicating with the HMC6343 compasss
	Wire.write(reg);             // Send the address of the register that we want to read
	Wire.endTransmission();

	Wire.requestFrom(HMC6343_ADDRESS, 6);    // Request six bytes of data from the HMC6343 compasss
	while(Wire.available() < 1);             // Busy wait while there is no byte to receive

	highByte = Wire.read();              // Reads in the bytes and convert them into proper degree units.
	lowByte = Wire.read();
	a = ((highByte << 8) + lowByte); // the heading in degrees

	highByte = Wire.read();
	lowByte = Wire.read();
	b = ((highByte << 8) + lowByte);   // the pitch in degrees

	highByte = Wire.read();
	lowByte = Wire.read();
	c = ((highByte << 8) + lowByte);    // the roll in degrees
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