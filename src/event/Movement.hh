#ifndef AERO_SRC_EVENT_MOVEMENT_HH
#define AERO_SRC_EVENT_MOVEMENT_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <minwindef.h>

// Define the Axis enum
enum Axis
{
	X = 0,
	Y = 1,
	Z = 2
};

VOID Walk(FLOAT fSpeed, Axis Direction);
VOID Rotate(FLOAT fDegree, Axis Pivot);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_EVENT_MOVEMENT_HH */