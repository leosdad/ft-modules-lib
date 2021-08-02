/*
  Ftmodules.cpp
*/

#include "Arduino.h"
#include <Wire.h>
#include "Ftmodules.h"

// SevenSegDisplay -------------------------------------------------------------

Ftmodules::SevenSegDisplay::SevenSegDisplay(int i2CPort)
{
	_i2cport = i2CPort;
	Wire.begin();
}

Ftmodules::SevenSegDisplay::Clear()
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdBlank);
	Wire.endTransmission();
}

Ftmodules::SevenSegDisplay::Test()
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdBlank);
	Wire.endTransmission();
}

Ftmodules::SevenSegDisplay::Show(char *str)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdDisplay);
	Wire.write(str);
	Wire.endTransmission();
}

Ftmodules::SevenSegDisplay::Flash(unsigned int ms)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdFlash);
	Wire.write(lowByte(ms));
	Wire.write(highByte(ms));
	Wire.endTransmission();
}

Ftmodules::SevenSegDisplay::Rotate(unsigned int ms)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdRotate);
	Wire.write(lowByte(ms));
	Wire.write(highByte(ms));
	Wire.endTransmission();
}

Ftmodules::SevenSegDisplay::Stop()
{
	Wire.beginTransmission(_i2cport);
	Wire.write(Ftmodules::SevenSegDisplay::cmdStop);
	Wire.endTransmission();
}


// -----------------------------------------------------------------------------
