#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Aero-Graphics.hh"

#include <Windows.h>
#include <winuser.h>
#include <winbase.h>
#include <winnt.h>

#include <basetsd.h>
#include <memoryapi.h>

using namespace Aero_Graphics;

PVOID Render::Block(PBYTE lpTexture)
{
	SIZE_T sTextureSize = 0;

	if (lpTexture != NULL) {
		PUINT32 textureSizeHeader = (PUINT32)(lpTexture + 16);
		sTextureSize = *textureSizeHeader;
	}

	if (sTextureSize == 0) {
		MessageBoxW(NULL, L"Invalid texture size.\n", L"Error", MB_OK);
		return nullptr;
	}

	PBYTE loadTexture = (PBYTE)VirtualAlloc(
		NULL,
		sTextureSize,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_READONLY
	);
	
	if (loadTexture == NULL) {
		MessageBoxW(NULL, L"Texture are null.\n", L"Error", MB_OK);
        return nullptr;
    }

	return nullptr;
}

PBYTE Render::Texture()
{
	BYTE a[] = {0x11, 0x12};

	BYTE b[] = {0x13, 0x14};

	PBYTE pData[] = {a, b};

	BYTE x = pData[0][1];
	
	
	return nullptr;
}

#endif /* defined(_WIN32) || defined(_WIN64) */