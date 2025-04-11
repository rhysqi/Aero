#ifndef AERO_CODEC_HH
#define AERO_CODEC_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winnt.h>

#include <Winuser.h>
#include <minwindef.h>

namespace Aero_Codec {
	typedef struct {
		PBYTE pbDataInput;
		SIZE_T pbDataSize;
		BOOL bInherit;
	} Encode_t, *pEncode_t;

	typedef union {
		PBYTE pbDataInput;
		SIZE_T pbDataSize;
		PBYTE pbDataOutput;
		BOOL bInherit;
	} Decode_t, *pDecode_t;

	namespace Audio {
		PBYTE pb_Encode_ACC(Encode_t Encode_ACC_t);
		PBYTE pb_Decode_AAC(CONST PBYTE encData, SIZE_T encSize);
	}
	
	namespace Format {
		PBYTE pb_aerotxtf(CONST PBYTE iData, SIZE_T iSize);
		PBYTE pb_aerosndf(CONST PBYTE iData, SIZE_T iSize);
	}

	namespace Image {
		PBYTE pb_Encode_JPEG(CONST PBYTE iData, SIZE_T iSize);
		PBYTE pb_Decode_JPEG(CONST PBYTE encData, SIZE_T encSize);
	}

	namespace Texture {
		PBYTE pb_Encode_BC7(CONST PBYTE iData, SIZE_T iSize);
		PBYTE pb_Decode_BC7(CONST PBYTE encData, SIZE_T encSize);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_CODEC_HH */