#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-Window.hh"

#include <Windows.h>

HWND Aero_Window::DWM::Base(LPCWSTR lpWindowName, WNDPROC wWindowProc)
{
	return NULL;
}

#endif /* defined(_WIN32) || defined(_WIN64) */