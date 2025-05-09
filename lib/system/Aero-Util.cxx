// ----------------------------------------
//  Utitlity functions for Aero System
//  This file is part of Aero System library
//  Included function:
//  - SIMD support check
//  - Display resolution check
//  - Window client area size check
//  - Sleep function
// ----------------------------------------
//  Written by: Risky Akbar, 2025
// ----------------------------------------

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winbase.h>

#include <windef.h>
#include <winnt.h>
#include <processthreadsapi.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

BOOL Aero_System::Util::SSE42_Support()
{
    if (IsProcessorFeaturePresent(PF_SSE4_2_INSTRUCTIONS_AVAILABLE)) {
        #ifdef _DEBUG
        MessageBoxW(NULL, L"SSE4.2 is supported", L"Information", MB_OK | MB_ICONINFORMATION);
        #endif /* _DEBUG */

        return TRUE;
    }
    #ifdef _DEBUG
    MessageBoxW(NULL, L"SSE4.2 is not supported", L"Information", MB_OK | MB_ICONERROR);
    #endif /* _DEBUG */

    return FALSE;
}

BOOL Aero_System::Util::AVX2_Support()
{
    if (IsProcessorFeaturePresent(PF_AVX2_INSTRUCTIONS_AVAILABLE)) {
        #ifdef _DEBUG
        MessageBoxW(NULL, L"AVX2 is supported", L"Information", MB_OK | MB_ICONINFORMATION);
        #endif /* _DEBUG */

        return TRUE;
    }
    #ifdef _DEBUG
    MessageBoxW(NULL, L"AVX2 is not supported", L"Information", MB_OK | MB_ICONERROR);
    #endif /* _DEBUG */

    return FALSE;
}

UINT Aero_System::Util::DisplayHeight()
{
	return GetSystemMetrics(SM_CXSCREEN);
}

UINT Aero_System::Util::DisplayWidth()
{
    #ifdef _DEBUG
    // LPCWSTR lpMessage = 

    #endif /* _DEBUG */
    wsprintfW(NULL, NULL, NULL);
	return GetSystemMetrics(SM_CYSCREEN);
}

UINT Aero_System::Util::WindowHeight(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.bottom - rect.top;
	}
	return 0;
}

UINT Aero_System::Util::WindowWidth(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.left - rect.right;
	}
	return 0;
}

VOID Aero_System::Util::MicroSleep(UINT64 uMicroSeconds)
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    UINT64 targetTicks = uMicroSeconds * frequency.QuadPart / 1000000;

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    
    LARGE_INTEGER current;
    do {
        QueryPerformanceCounter(&current); 
    } while ((current.QuadPart - start.QuadPart) < targetTicks);
}

VOID Aero_System::Util::NanoSleep(UINT64 uwNanoSeconds)
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    UINT64 targetTicks = uwNanoSeconds * frequency.QuadPart / 1000000000;

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    
    LARGE_INTEGER current;
    do {
        QueryPerformanceCounter(&current); 
    } while ((current.QuadPart - start.QuadPart) < targetTicks);
}

#endif /* defined(_WIN32) || defined(_WIN64) */