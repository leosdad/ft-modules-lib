/*
	Sounds class public methods
*/

#include <Arduino.h>
#include "Ftmodules.h"

void Ftmodules::Sounds::Init(I2C i2c, int soundCommand)
{
	_i2c = i2c;
	_soundCommand = soundCommand;
}

void Ftmodules::Sounds::Play(int soundIndex)
{
	_i2c.Cmd(_soundCommand, soundIndex);
}
