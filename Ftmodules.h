/*
  ftmodules.h
*/
#ifndef ftmodules_h
#define ftmodules_h

#include "Arduino.h"

class Ftmodules
{

public:
	// Ftmodules();

	// MotorDriver class -------------------------------------------------------

	class MotorDriver
	{

	public:
		// Commands for motor driver module

		enum Command
		{
			cmdHello = 0x21,
			cmdOutput1 = 0x31,
			cmdOutput2 = 0x32,
			cmdOutput3 = 0x33,
			cmdOutput4 = 0x34,
			cmdMode = 0x40,
			cmdSpeed = 0x41,
			cmdCoast = 0x42,
			cmdForward = 0x43,
			cmdBackwards = 0x44,
			cmdBrake = 0x45,
			cmdHome = 0x46,
			cmdTarget = 0x49,
		};

	private:
		int _i2cport;
	};

	// SevenSegDisplay class ---------------------------------------------------

	class SevenSegDisplay
	{

	public:
		SevenSegDisplay(int i2CPort);
		Clear();
		Test();
		Show(char *str);
		Flash(unsigned int ms);
		Rotate(unsigned int ms);
		Stop();

		// Commands for 7-segment display module

		enum Command
		{
			cmdBlank = 0x10,
			cmdTest = 0x11,
			cmdDisplay = 0x12,
			cmdFlash = 0x13,
			cmdRotate = 0x14,
			cmdStop = 0x40,
		};

	private:
		int _i2cport;
	};
};

#endif // ftmodules
