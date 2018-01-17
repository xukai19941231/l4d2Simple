#pragma once
#include "../Utils/checksum_crc.h"
#include "../../l4d2Simple2/vector.h"
#include <Windows.h>

class CUserCmd
{
public:
	CRC32_t GetChecksum();

	byte pad_0x0000[0x4];		// 0x0000 - VTable
	int command_number;			// 0x0004	For matching server and client commands for debugging
	int tick_count;				// 0x0008	the tick the client created this command
	QAngle viewangles;			// 0x000C	Player instantaneous view angles.
	float fowardmove;			// 0x0018
	float sidemove;				// 0x001C
	float upmove;				// 0x0020
	int buttons;				// 0x0024	Attack button states
	// byte impulse;			// 0x0028
	// int weaponselect;		// 0x002A	Current weapon id
	// int weaponsubtype;		// 0x002E
	byte pad_0x0028[0xC];		// 0x0032
	int random_seed;			// 0x0034	For shared random functions
	// short mousedx;			// 0x0038	mouse accum in x from create move
	// short mousedy;			// 0x003A	mouse accum in y from create move
	// Vector headangles;		// 0x003C
	// Vector headoffset;		// 0x0048
	byte pad_0x0038[0x20];		// 0x0038
};	// Size = 0x0058
