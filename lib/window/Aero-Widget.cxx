#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-Window.hh"

#include <Windows.h>
#include <winnt.h>

using namespace Aero_Window;

HWND Widget::Button(LPCWSTR lpButtonText, BOOL bInherit, WNDPROC wButtonProc)
{
	
	LPCWSTR CLASS_NAME = L"Aero-Button";
	WNDCLASSW wcw = { };

	wcw.lpfnWndProc = wButtonProc;
	wcw.lpszClassName = CLASS_NAME;

	HWND hWnd;

	return hWnd;
}

#endif /* defined(_WIN32) || defined(_WIN64) */