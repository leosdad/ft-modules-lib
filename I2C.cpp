/*
	I2C class public methods
*/

#include <Arduino.h>
#include <Wire.h>
#include "Ftmodules.h"

#pragma region I²C command functions -------------------------------------------

byte _address;

void Ftmodules::I2C::Init(int address)
{
	Wire.begin();
	_address = address;
}

void Ftmodules::I2C::Cmd(byte cmd)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.endTransmission();
}

void Ftmodules::I2C::Cmd(byte cmd, byte param)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

void Ftmodules::I2C::Cmd(byte cmd, byte param1, byte param2)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.endTransmission();
}

void Ftmodules::I2C::Cmd(byte cmd, byte param1, byte param2, byte param3)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.endTransmission();
}

void Ftmodules::I2C::Cmd(byte cmd, byte param1, byte param2, byte param3, byte param4)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.write(param4);
	Wire.endTransmission();
}

void Ftmodules::I2C::Cmd(int cmd, char *param)
{
	Wire.beginTransmission(_address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

#pragma endregion --------------------------------------------------------------
