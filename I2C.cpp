/*
	I2C class public methods
*/

#include <Arduino.h>
#include <Wire.h>
#include "FtModules.h"

#pragma region I²C command functions -------------------------------------------

// byte FtModules::I2C::address;

// void FtModules::I2C::Init(int address)
// {
// 	// Wire.begin();
// 	address = address;
// }

// int FtModules::I2C::GetAddress()
// {
// 	return address;
// }

void FtModules::I2C::Cmd(int address, byte cmd)
{
	// if(address == 0) { Serial.print("Zero 1: "); Serial.println(cmd); }
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.endTransmission();
}

void FtModules::I2C::Cmd(int address, byte cmd, byte param)
{
	// if(address == 0) Serial.println("Zero 2");
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

void FtModules::I2C::Cmd(int address, byte cmd, byte param1, byte param2)
{
	// if(address == 0) Serial.println("Zero 3");
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.endTransmission();
}

void FtModules::I2C::Cmd(int address, byte cmd, byte param1, byte param2, byte param3)
{
	// if(address == 0) Serial.println("Zero 4");
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.endTransmission();
}

void FtModules::I2C::Cmd(int address, byte cmd, byte param1, byte param2, byte param3, byte param4)
{
	// if(address == 0) Serial.println("Zero 5");
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param1);
	Wire.write(param2);
	Wire.write(param3);
	Wire.write(param4);
	Wire.endTransmission();
}

void FtModules::I2C::Cmd(int address, int cmd, char *param)
{
	// if(address == 0) Serial.println("Zero 6");
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.write(param);
	Wire.endTransmission();
}

#pragma endregion --------------------------------------------------------------
