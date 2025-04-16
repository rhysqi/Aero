#ifndef AERO_AUDIO_HH
#define AERO_AUDIO_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
#include <WaaSApi.h>

namespace Aero_Audio {
	typedef union {
		PBYTE pDataInput;
		SIZE_T iDataSize;
		BOOL bInherit;
	} Stream_t, *pStream_t;

}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_AUDIO_HH */