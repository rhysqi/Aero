#ifndef AERO_WINDOW_HH
#define AERO_WINDOW_HH

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>
#include <minwindef.h>

namespace Aero_Window {
	namespace DWM {
		HWND Base(LPCWSTR lpWindowName, WNDPROC wWindowProc);
		HWND Fancy(LPCWSTR lpWindowName, WNDPROC wWindowProc);
	}
	
	namespace Widget {
		HWND Button(LPCWSTR lpButtonText, BOOL bInherit, WNDPROC wButtonProc);
		HWND Label(LPCWSTR lpLabelText, BOOL bInherit);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_WINDOW_HH */