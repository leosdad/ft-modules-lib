/*
  Header for fischertechnik modules class
*/

#ifndef ftmodules_h
#define ftmodules_h

#include <Arduino.h>
#include <Simpletypes.h>

class FtModules
{
  public:

	// ----------------------------- I²C

	class I2C
	{
	  public:
		static void Cmd(int address, byte cmd);
		static void Cmd(int address, byte cmd, byte param);
		static void Cmd(int address, byte cmd, byte param1, byte param2);
		static void Cmd(int address, byte cmd, byte param1, byte param2, byte param3);
		static void Cmd(int address, byte cmd, byte param1, byte param2, byte param3, byte param4);
		static void Cmd(int address, int cmd, char *param);
	};

	// ----------------------------- Seven-segment display

	class SevenSegDisplay
	{

	  public:
		// void Clear(int address);
		// void Test(int address);
		// void Display(int address, char *str);
		// void Hold(int address, uint ms);
		// void Flash(int address, uint ms);
		// void Rotate(int address, uint ms);
		// void Stop(int address);

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

	  	static const byte maxDisplayChars = 80;
	};

	// ----------------------------- Motor driver

	class MotorDriver
	{
	  public:

		MotorDriver(FtModules::I2C i2c);

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
		FtModules::I2C _i2c;
	};

};

#endif // ftmodules_h
