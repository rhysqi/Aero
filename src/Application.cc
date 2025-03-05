#include <Windows.h>
#include <synchapi.h>
#include <winnt.h>

#include <Pdh.h>

#include <profileapi.h>
#include <errhandlingapi.h>

#include <wchar.h>

void PerformCounter()
{
    LARGE_INTEGER pfc;
    QueryPerformanceFrequency(&pfc);

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    int divisor = 1000000000;
    
    double Seconds = ((double)pfc.QuadPart / frequency.QuadPart) / divisor;
    wprintf(L"Time in Seconds: %.9f seconds\n", Seconds);

    ULONGLONG NanoSeconds = (pfc.QuadPart * divisor) / frequency.QuadPart;
    wprintf(L"Time in Nano Seconds: %llu ns\n", NanoSeconds / divisor);
}

int wmain(int argc, const wchar_t *argv[]){
    
    PerformCounter();
    
    return 0;
}