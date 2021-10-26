/*
  ftmodules.h
*/

#ifndef ftmodules_h
#define ftmodules_h

#include <Arduino.h>
#include <Simpletypes.h>

class Ftmodules
{
  public:
	class I2C
	{
	  public:
		void Init(int address);
		void Cmd(byte cmd);
		void Cmd(byte cmd, byte param);
		void Cmd(byte cmd, byte param1, byte param2);
		void Cmd(byte cmd, byte param1, byte param2, byte param3);
		void Cmd(byte cmd, byte param1, byte param2, byte param3, byte param4);
		void Cmd(int cmd, char *param);

	  private:
		byte _address;
	};

	class Sounds
	{
	  public:
		void Init(I2C i2c, int soundCommand);
		void Play(int soundIndex);

	  private:
		Ftmodules::I2C _i2c;
		int _soundCommand;
	};

	class MotorDriver
	{
	  public:

		MotorDriver(Ftmodules::I2C i2c);

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
		Ftmodules::I2C _i2c;
	};

	class SevenSegDisplay
	{

	  public:
		void Init(I2C i2c);
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
		Ftmodules::I2C _i2c;
	};
};

#endif // ftmodules_h
