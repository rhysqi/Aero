#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-System.hh"

#include <winnt.h>

#include <memoryapi.h>
#include <heapapi.h>
#include <handleapi.h>

LPVOID Aero_System::Pool::Memory::Virtual::Create(INT PoolCount, LPVOID lpMemoryInit)
{
	LPVOID hMemory = lpMemoryInit;
	LPVOID* hPool = (LPVOID*)HeapAlloc(
		GetProcessHeap(), HEAP_ZERO_MEMORY,
		sizeof(LPVOID) * PoolCount
	);

	for (INT MemCounter = 0; MemCounter < PoolCount; ++MemCounter) {
		
		hPool[MemCounter] = hMemory;
		if (!hMemory) {
			Aero_System::Inform::ShowLastError();
			return nullptr;
		}
	}

	return (LPVOID)hPool;
}

#endif /* defined(_WIN32) || defined(_WIN64) */