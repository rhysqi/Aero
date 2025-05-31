#ifndef AERO_SYSTEM_HH
#define AERO_SYSTEM_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#define AERO_USE_MIN_POOL 4
#define AERO_USE_MAX_POOL (AERO_USE_MIN_POOL << 4)

#define AERO_1_BYTES_OFFSET 1
#define AERO_2_BYTES_OFFSET 2
#define AERO_4_BYTES_OFFSET 4
#define AERO_8_BYTES_OFFSET 8

#define AERO_SSE_BYTES_OFFSET 16
#define AERO_AVX_BYTES_OFFSET 32
#define AERO_AVX512_BYTES_OFFSET 64

#include <windows.h>
#include <winnt.h>
#include <minwindef.h>

#include <basetsd.h>

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

	// Pool definition
	namespace Pool {

		// Memory definition
		namespace Memory {

			// Heap definition
			namespace Heap {
				typedef struct {
					LPVOID lpMemoryPool;
					INT PoolCount;
					UINT uOffset;
				} Heap_Pool_t, *pHeap_Pool_t;

				LPVOID Alloc(INT PoolCount, pHeap_Pool_t pHeapPool);
				UINT CountPool(LPVOID *lpMemoryPool);
				LPVOID Peek(LPVOID *lpMemoryPool, UINT uIndex);

				BOOL Lock(LPVOID *lpMemoryPool);
				BOOL LockEx(LPVOID *lpMemoryPool, UINT uIndex);
				BOOL Unlock(LPVOID *lpMemoryPool);
				BOOL UnlockEx(LPVOID *lpMemoryPool, UINT uIndex);
				BOOL Free(LPVOID *lpMemoryPool);
				BOOL FreeEx(LPVOID *lpMemoryPool, UINT uIndex);
				BOOL Destroy(LPVOID *lpMemoryPool);
				BOOL DestroyEx(LPVOID *lpMemoryPool, UINT uIndex);
			}

			// Virtual definition
			namespace Virtual {
				typedef struct {
					LPVOID lpAddress;
					SIZE_T dwSize;
					DWORD dwProtection;
					DWORD flAllocationType;
					UINT uOffset;
				} Virtual_Pool_t, *pVirtual_Pool_t;

				LPVOID Alloc(INT PoolCount, pVirtual_Pool_t pVirtualPool);
				UINT CountPool(LPVOID *lpMemoryPool);
				LPVOID Peek(LPVOID *lpMemoryPool, UINT uIndex);

				BOOL Protect(LPVOID *lpMemoryPool, DWORD dwProtection);
				BOOL ProtectEx(LPVOID *lpMemoryPool, DWORD dwProtection, UINT uIndex);
				BOOL Lock(LPVOID *lpMemoryPool);
				BOOL LockEx(LPVOID *lpMemoryPool, UINT uIndex);
				BOOL Unlock(LPVOID *lpMemoryPool);
				BOOL UnlockEx(LPVOID *lpMemoryPool, UINT uIndex);
				BOOL Free(LPVOID *lpMemoryPool, DWORD dwFreeType);
				BOOL FreeEx(LPVOID *lpMemoryPool, DWORD dwFreeType, UINT uIndex);
			}
		}

		// Thread Definition
		namespace Thread {
			
		}
	}

	// Types definition
	namespace Types {
		typedef LPINT *LPPINT;
		typedef LPBOOL *LPPBOOL;
		typedef LPCSTR *LPPCSTR;
		typedef LPCWSTR *LPPCWSTR;
		typedef LPVOID *LPPVOID;
		typedef LPWORD *LPPWORD;
		typedef LPBYTE *LPPBYTE;
		
		typedef PINT *PPINT;
		typedef PFLOAT *PPFLOAT;
		typedef PBOOL *PPBOOL;
		typedef PCHAR *PPCHAR;
		typedef PSTR *PPSTR;
		typedef PWCHAR *PPWCHAR;
		typedef PVOID *PPVOID;
		typedef PWORD *PPWORD;
		typedef PBYTE *PPBYTE;
	}

	// Utils definition
	namespace Util {
		BOOL SSE42_Support();
		BOOL AVX2_Support();
		BOOL GPU_Enums();
		
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