#ifndef AERO_SYSTEM_HH
#define AERO_SYSTEM_HH

#if defined(_WIN32) | defined(_WIN64)

#include <windows.h>

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
		UINT DisplayHeight();
		UINT DisplayWidth();

		UINT WindowClientHeight(HWND hWnd);
		UINT WindowClientWidth(HWND hWnd);

		UINT WindowHeight(HWND hWnd);
		UINT WindowWidth(HWND hWnd);

		VOID NanoSleep(UINT64 uNanoSeconds);
	}
}

#endif /* defined(_WIN32) | defined(_WIN64) */
#endif /* AERO_SYSTEM_HH */