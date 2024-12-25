#ifndef AERO_SYSTEM_HH
#define AERO_SYSTEM_HH

#if defined(_WIN32) | defined(_WIN64)

#include <windows.h>
#include <minwindef.h>

namespace Aero_System {
	namespace Directory {
		HANDLE Create(LPCWSTR DirName, LPSECURITY_ATTRIBUTES AttrSec);
		HANDLE Remove(LPCWSTR DirName);
	}

	namespace File {
		HANDLE Create(LPCWSTR FileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute);
		BOOL Read(LPCWSTR FileName);
		BOOL ReadEx(LPCWSTR FileName);
		BOOL Write(HANDLE hFile, LPCWSTR FileBuffer);
	}

	namespace Util {
		UINT ScreenHeight();
		UINT ScreenWidth();

		UINT WindowHeight(HWND hWnd);
		UINT WindowWidth(HWND hWnd);
	}
}

#endif /* defined(_WIN32) | defined(_WIN64) */
#endif /* AERO_SYSTEM_HH */