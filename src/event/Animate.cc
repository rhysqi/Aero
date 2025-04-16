#include "Animate.hh"

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-System.hh"
#include <handleapi.h>

PVOID Linear(FLOAT fSpeed)
{
	if (!fSpeed)
	{
		Aero_System::Inform::ShowLastError();
		return (PVOID)NULL;
	}
	
	PFLOAT pValue = &fSpeed;
	return (PVOID)pValue;
}

PVOID EaseIn_Miliseconds(pAero_Easing_Data_t Easing_Data)
{
	if (!Easing_Data)
	{
		Aero_System::Inform::ShowLastError();
		return (PVOID)NULL;
	}

	return (PVOID)Easing_Data;
}

#endif /* defined(_WIN32) || defined(_WIN64) */