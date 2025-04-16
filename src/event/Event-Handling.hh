#ifndef AERO_SRC_EVENT_EVENT_HANDLING_HH
#define AERO_SRC_EVENT_EVENT_HANDLING_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

BOOL Event_Delay(HWND hWnd, UINT64 uMicroSeconds);
BOOL Event_Interval(HWND hWnd, UINT64 uMicroSeconds);
VOID Event_Queue(HWND hWnd, ...);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_EVENT_EVENT_HANDLING_HH */