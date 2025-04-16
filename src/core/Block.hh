#ifndef AERO_SRC_CORE_BLOCK_HH
#define AERO_SRC_CORE_BLOCK_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <memoryapi.h>

typedef struct
{
	UINT16 block_id;
	LPCWSTR block_filepath;
	PBYTE blockTexture;
} Aero_Block_t, *pAero_Block_t;

inline PBYTE Aero_Block_Init(Aero_Block_t Block_Data)
{
	
}

inline BOOL Aero_Block_Texture(UINT16 Block_ID, PBYTE Texture_Buffer)
{
	
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_CORE_BLOCK_HH */