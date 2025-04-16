#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-Window.hh"

#include <Windows.h>
#include <winnt.h>

HWND Aero_Window::Widget::Button(LPCWSTR lpButtonName, BOOL bInherit, WNDPROC wButtonProc)
{
	LPCWSTR CLASS_NAME = L"Aero-Button";
	WNDCLASSW wcw = { };

	wcw.lpfnWndProc = wButtonProc;
	wcw.lpszClassName = CLASS_NAME;

	HWND hWnd;

	

	return hWnd;
}

#endif /* defined(_WIN32) || defined(_WIN64) */