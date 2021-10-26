/*
  ftmodules.h
*/
#ifndef ftmodules_h
#define ftmodules_h

#include "Arduino.h"
#include "Simpletypes.h"

class Ftmodules
{

public:

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

		void Clear();
		void Test();
		void Show(char *str);
		void Hold(uint ms);
		void Flash(uint ms);
		void Rotate(uint ms);
		void Stop();

		// Commands for 7-segment display module

		enum Command
		{
			cmdBlank = 0x10,
			cmdTest = 0x11,
			cmdDisplay = 0x12,
			cmdFlash = 0x13,
			cmdRotate = 0x14,
			cmdHold = 0x15,
			cmdStop = 0x40,
		};

	private:
		int _i2cport;
		void i2cCommand(int cmd);
		void i2cCommand(int cmd, int param1);
		void i2cCommand(int cmd, uint param1);
		void i2cCommand(int cmd, char *param1);
	};
};

#endif // ftmodules_h
