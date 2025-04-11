#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>
#include <minwinbase.h>

#include <memoryapi.h>
#include <handleapi.h>
#include <fileapi.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

HANDLE Aero_System::File::Create(LPCWSTR lpFileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute)
{
	LPSECURITY_ATTRIBUTES saFile = (LPSECURITY_ATTRIBUTES)VirtualAlloc(
		NULL,
		sizeof(SECURITY_ATTRIBUTES),
		MEM_COMMIT | MEM_RESERVE,
		PAGE_READWRITE
	);

	if (saFile == NULL) {
		Inform::ShowLastError();
		return NULL;
	}

	saFile->bInheritHandle = FALSE;
	saFile->nLength = sizeof(SECURITY_ATTRIBUTES);

	DWORD oldProtect;
	VirtualProtect(
		saFile,
		sizeof(SECURITY_ATTRIBUTES),
		PAGE_READONLY,
		&oldProtect
	);

	HANDLE hFile = CreateFileW(
		lpFileName,
		GENERIC_WRITE | GENERIC_READ,
		0, saFile,
		CREATE_NEW,
		dwFlagsAndAttribute,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		Inform::ShowLastError();
		return (HANDLE)-1;
	}
	
	return hFile;
}

BOOL Aero_System::File::Write(HANDLE hFile, LPCWSTR lpFileBuffer)
{
	BOOL hWrite = WriteFile(
		hFile,
		lpFileBuffer,
		lstrlenW(lpFileBuffer) * sizeof(WCHAR),
		0,
		NULL
	);
	
	if (hWrite == FALSE) {
		Inform::ShowLastError();
		return FALSE;
	}

	return hWrite;
}

BOOL Aero_System::File::Read(LPCWSTR lpFileName)
{
	BOOL hFile = ReadFile(
		NULL, NULL,
		NULL, NULL, NULL
	);

	return TRUE;
}

#endif /* defined(_WIN32) || defined(_WIN64) */