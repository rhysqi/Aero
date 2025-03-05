#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <basetsd.h>
#include <winnt.h>
#include <minwindef.h>

typedef union
{
	UINT16 block_id;
	LPCWSTR blockName;
} Aero_Block_t;

PBYTE Aero_Block_Init();