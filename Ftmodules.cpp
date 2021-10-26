/*
  Ftmodules.cpp
*/

#include <Arduino.h>
#include <Wire.h>
#include "Ftmodules.h"

// SevenSegDisplay -------------------------------------------------------------

Ftmodules::SevenSegDisplay::SevenSegDisplay(int i2CPort)
{
	_i2cport = i2CPort;
	Wire.begin();
}

void Ftmodules::SevenSegDisplay::Clear()
{
	i2cCommand(cmdBlank);
}

void Ftmodules::SevenSegDisplay::Test()
{
	i2cCommand(cmdTest);
}

void Ftmodules::SevenSegDisplay::Show(char *str)
{
	i2cCommand(cmdDisplay, str);
	// Wire.beginTransmission(_i2cport);
	// Wire.write(Ftmodules::SevenSegDisplay::cmdDisplay);
	// Wire.write(str);
	// Wire.endTransmission();
}

void Ftmodules::SevenSegDisplay::Hold(uint ms)
{
	i2cCommand(cmdHold, ms);
}

void Ftmodules::SevenSegDisplay::Flash(uint ms)
{
	i2cCommand(cmdFlash, ms);
}

void Ftmodules::SevenSegDisplay::Rotate(uint ms)
{
	i2cCommand(cmdRotate, ms);
}

void Ftmodules::SevenSegDisplay::Stop()
{
	i2cCommand(cmdStop);
}

#pragma region I²C command functions -------------------------------------------

void Ftmodules::SevenSegDisplay::i2cCommand(int cmd)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(cmd);
	Wire.endTransmission();
}

void Ftmodules::SevenSegDisplay::i2cCommand(int cmd, int param)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

void Ftmodules::SevenSegDisplay::i2cCommand(int cmd, char *param)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

void Ftmodules::SevenSegDisplay::i2cCommand(int cmd, uint param)
{
	Wire.beginTransmission(_i2cport);
	Wire.write(cmd);
	Wire.write(lowByte(param));
	Wire.write(highByte(param));
	Wire.endTransmission();
}

#pragma endregion --------------------------------------------------------------

// -----------------------------------------------------------------------------
