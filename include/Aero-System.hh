#ifndef AERO_SYSTEM_HH
#define AERO_SYSTEM_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
#include <winnt.h>

namespace Aero_System {
	// Diagnostic definition
	namespace Diagnostic {
		HANDLE FileWatcher(LPCWSTR lpFilepath);
		HANDLE CPU_Usage(UINT64 uInterval);
	}

	// Directory definition
	namespace Directory {
		HANDLE Create(LPCWSTR lpDirName, LPSECURITY_ATTRIBUTES saAttrSec);
		HANDLE Remove(LPCWSTR lpDirName);
	}

	// File definition
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

	// Memory Pool definition
	namespace Pool {
		namespace Memory {
			namespace Heap {
				LPVOID Create(INT PoolCount, LPVOID lpMemoryInit);
				BOOL CountPool(LPVOID lpMemoryPool);

				BOOL Lock(LPVOID lpMemoryPool);
				BOOL Unlock(LPVOID lpMemoryPool);
				BOOL Free(LPVOID lpMemoryPool);
				BOOL Destroy(LPVOID lpMemoryPool);
			}

			namespace Virtual {
				LPVOID Create(INT PoolCount, LPVOID lpMemoryInit);
				BOOL CountPool(LPVOID lpMemoryPool, DWORD dwProtection);

				BOOL Protect(LPVOID lpMemoryPool, DWORD dwProtection);
				BOOL Lock(LPVOID lpMemoryPool);
				BOOL Unlock(LPVOID lpMemoryPool);
				BOOL Free(LPVOID lpMemoryPool);
				BOOL Destroy(LPVOID lpMemoryPool);
			}
		}

		namespace Process {
			LPBOOL Create(UINT32 dwProcessCount, BOOL bProcessInit);
			LPBOOL Terminate(HANDLE hProcess, DWORD dwExitCode);
		}
	}

	// Utils definition
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