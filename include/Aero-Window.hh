#ifndef AERO_WINDOW_HH
#define AERO_WINDOW_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winuser.h>

namespace Aero_Window {
	// Window definition
	namespace DWM {
		HWND Base(LPCWSTR lpWindowName, WNDPROC wWindowProc);
		HWND Fancy(LPCWSTR lpWindowName, WNDPROC wWindowProc);
	}
	
	// Widget definition
	namespace Widget {
		HWND Button(LPCWSTR lpButtonName, BOOL bInherit, WNDPROC wButtonProc);
		HWND Label(LPCWSTR lpLabelName, BOOL bInherit);
		HWND Textbox(LPCWSTR lpTextBoxName, LPWSTR lpTextBoxPlaceholder, BOOL bInherit);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_WINDOW_HH */