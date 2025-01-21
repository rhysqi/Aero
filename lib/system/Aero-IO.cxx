#if defined(_WIN32) | defined(_WIN64)

#include "../../include/Aero-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>

#include <fileapi.h>
#include <handleapi.h>

#include <wchar.h>

using namespace Aero_System;

HANDLE File::Create(LPCWSTR FileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute)
{
	HANDLE hFile = CreateFileW(
		FileName,
		GENERIC_WRITE | GENERIC_READ,
		0, AttrSec,
		CREATE_NEW,
		dwFlagsAndAttribute,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		DWORD errorCode = GetLastError();
		wprintf(L"Error: Failed to make file, error code (%lu)\n", errorCode);
		return (HANDLE)-1;
	}
	
	return hFile;
}

BOOL File::Write(HANDLE hFile, LPCWSTR FileBuffer)
{
	BOOL hWrite = WriteFile(
		hFile,
		FileBuffer,
		sizeof(FileBuffer),
		0,
		NULL
	);

	if (hWrite == FALSE) {
		MessageBoxW(NULL, L"Failed to write to file!", L"Error", MB_OK);
		return FALSE;
	}

	return TRUE;
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