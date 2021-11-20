// -----------------------------------------------------------------------------

// Dirty Dishes pinball: Child Arduino
// Rubem Pechansky 2021

// -----------------------------------------------------------------------------

#ifndef pb_child_h
#define pb_child_h

#define CHILD_ADDRESS		0x10
#define NLEDS				9
#define SERVO_TIMER			300

// Commands

enum class childCommands
{
	RESET = 0x10,
	PORT,
	SERVO,
	SOUND,
	LED,
	MOTOR,
};

enum class childLeds
{
	ROLLOVER1 = 0,
	ROLLOVER2,
	ROLLOVER3,
	ROLLOVER_SKILL,
	HOLD,
	RIGHT_OUTLANE,
	LEFT_OUTLANE,
	LEFT_ORBIT,
	LIGHTS,
};

enum class servoCmd
{
	CLOSE = 1,
	OPEN,
};

enum class outState
{
	OFF = 0,
	ON = 1,
	FLASH,
	ONESHOT,
};

enum soundNames
{
	DING = 1,
	BOING,
	WHISTLE,
	CLANG,
	BAMBOO,
};

#endif // pb_child_h
