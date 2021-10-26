/*
	SevenSegDisplay class public methods
*/

#include <Arduino.h>
#include <Wire.h>
#include "Ftmodules.h"

// SevenSegDisplay -------------------------------------------------------------

void Ftmodules::SevenSegDisplay::Init(I2C i2c)
{
	_i2c = i2c;
	Wire.begin();
}

void Ftmodules::SevenSegDisplay::Clear()
{
	_i2c.Cmd(cmdBlank);
}

void Ftmodules::SevenSegDisplay::Test()
{
	_i2c.Cmd(cmdTest);
}

void Ftmodules::SevenSegDisplay::Show(char *str)
{
	_i2c.Cmd(cmdDisplay, str);
}

void Ftmodules::SevenSegDisplay::Hold(uint ms)
{
	_i2c.Cmd(cmdHold, ms);
}

void Ftmodules::SevenSegDisplay::Flash(uint ms)
{
	_i2c.Cmd(cmdFlash, ms);
}

void Ftmodules::SevenSegDisplay::Rotate(uint ms)
{
	_i2c.Cmd(cmdRotate, ms);
}

void Ftmodules::SevenSegDisplay::Stop()
{
	_i2c.Cmd(cmdStop);
}
