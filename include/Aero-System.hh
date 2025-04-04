#ifndef AERO_SYSTEM_HH
#define AERO_SYSTEM_HH

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
#include <winnt.h>

namespace Aero_System {
	namespace Diagnostic {
		HANDLE FileWatcher(LPCWSTR lpFilepath);
		HANDLE CPU_Usage(UINT64 uInterval);
	}

	namespace Directory {
		HANDLE Create(LPCWSTR lpDirName, LPSECURITY_ATTRIBUTES saAttrSec);
		HANDLE Remove(LPCWSTR lpDirName);
	}

	namespace File {
		HANDLE Create(LPCWSTR FileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute);

		HANDLE CreateMapping();

		BOOL Read(LPCWSTR FileName);
		BOOL ReadEx(LPCWSTR FileName);

		BOOL Write(HANDLE hFile, LPCWSTR lpFileBuffer);
		BOOL WriteEx(HANDLE hFile, LPCWSTR lpFileBuffer);
	}

	// Inform definition
    namespace Inform {
		INT ShowErrorWithoutTerminate();
		INT ShowLastError();
		INT ShowMessage(LPCWSTR lpMessage);
    }

	namespace Pool {
		namespace Memory {
			HANDLE Virtual(INT PoolCount, LPVOID lpMemoryInit);
			HANDLE Heap(INT PoolCount, LPVOID lpMemoryInit);

			BOOL Lock(HANDLE lpMemoryPool);
			BOOL Unlock(HANDLE lpMemoryPool);
			BOOL Free(HANDLE lpMemoryPool);
			BOOL Destroy(HANDLE lpMemoryPool);
		}
	}

	namespace Util {
		UINT DisplayHeight();
		UINT DisplayWidth();

		UINT WindowClientHeight(HWND hWnd);
		UINT WindowClientWidth(HWND hWnd);

		UINT WindowHeight(HWND hWnd);
		UINT WindowWidth(HWND hWnd);

		VOID MicroSleep(UINT64 uMicroSeconds);
		VOID NanoSleep(UINT64 uNanoSeconds);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SYSTEM_HH */