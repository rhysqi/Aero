#include "Event-Handling.hh"

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-System.hh"

BOOL Event_Delay(HWND hWnd, UINT64 uMicroSeconds)
{
	if (!hWnd)
	{
		Aero_System::Inform::ShowLastError();
		return FALSE;
	}

	PVOID x;

	x = (PINT)100;


	return FALSE;
}

BOOL Event_Interval(HWND hWnd, UINT64 uMicroSeconds)
{
	
	return FALSE;
}

VOID Event_Queue(HWND hWnd, ...)
{
	__asm__{
		mov eax, ecx
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */