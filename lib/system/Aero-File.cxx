#if defined(_WIN32) | defined(_WIN64)

#include "../../include/Aero-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>
#include <minwinbase.h>

#include <memoryapi.h>
#include <handleapi.h>
#include <fileapi.h>

using namespace Aero_System;

HANDLE File::Create(LPCWSTR FileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute)
{
	LPSECURITY_ATTRIBUTES saFile = (LPSECURITY_ATTRIBUTES)VirtualAlloc(
		NULL, sizeof(SECURITY_ATTRIBUTES), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE
	);

	if (saFile == NULL) {
		Error::ShowLastError();
		return NULL;
	}

	saFile->bInheritHandle = FALSE;
	saFile->nLength = sizeof(SECURITY_ATTRIBUTES);

	HANDLE hFile = CreateFileW(
		FileName,
		GENERIC_WRITE | GENERIC_READ,
		0, saFile,
		CREATE_NEW,
		dwFlagsAndAttribute,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		Error::ShowLastError();
		return (HANDLE)-1;
	}
	
	return hFile;
}

BOOL File::Write(HANDLE hFile, LPCWSTR FileBuffer)
{
	BOOL hWrite = WriteFile(
		hFile,
		FileBuffer,
		lstrlenW(FileBuffer) * sizeof(WCHAR),
		0,
		NULL
	);
	
	if (hWrite == FALSE) {
		Error::ShowLastError();
		return FALSE;
	}

	return hWrite;
}

BOOL File::Read(LPCWSTR FileName)
{
	BOOL hFile = ReadFile(
		NULL, NULL,
		NULL, NULL, NULL
	);

	return TRUE;
}

#endif /* defined(_WIN32) | defined(_WIN64) */