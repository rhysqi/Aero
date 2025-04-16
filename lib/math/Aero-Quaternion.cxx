#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-Math.hh"
#include "../../include/Aero-System.hh"

#include <Windows.h>

PVOID Aero_Math::Quaternion::Add(pQuaternion_t q1, pQuaternion_t q2)
{
	if (!q1 || !q2)
	{
		Aero_System::Inform::ShowLastError();
		return NULL;
	}

	pQuaternion_t qResult = (pQuaternion_t)HeapAlloc(
		GetProcessHeap(),
		HEAP_ZERO_MEMORY,
		sizeof(Quaternion_t)
	);

	if (!qResult)
	{
		Aero_System::Inform::ShowLastError();
		return NULL;
	}
	
	qResult->fX = q1->fX + q2->fX;
	qResult->fY = q1->fY + q2->fY;
	qResult->fZ = q1->fZ + q2->fZ;
	qResult->fW = q1->fW + q2->fW;

	return (PVOID)qResult;
}

#endif /* defined(_WIN32) || defined(_WIN64) */