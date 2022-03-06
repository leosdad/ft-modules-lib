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

/*
 * Sounds provided by https://freesound.org/
 */

enum soundNames
{
	DING = 1,		// Ding-ding-small-bell by JohnsonBrandEditing
	DRAIN,			// Water-go-down-the-hole by Incarnadine
	GLASS,			// Glass-break-medium-jar by RoganMcDougald
	CLANG,			// Donk-metal-glass by EminYILDIRIM
	FAUCET,			// Water-pour-sink-a by InspectorJ (www.jshaw.co.uk)
	CRASH,			// Crashing glassbottles by RackhamsReverse
	FRYING,			// Food-frying by TyroneW
	BUBBLES,		// Bubbles by ManuelAurreaf
	CABINET,		// Glass-shake-cabinet-closet by Garuda1982
	SHAKE,			// Water by TechyActor15
	BELL,			// Glass Bell Ringing by f-r-a-g-i-l-e
};

#endif // pb_child_h
