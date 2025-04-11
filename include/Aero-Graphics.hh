#ifndef AERO_GRAPHICS_HH
#define AERO_GRAPHICS_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <Winuser.h>
#include <winnt.h>

namespace Aero_Graphics {
	// Utils definitions
	namespace Util {
		INT32 getFPS(HWND hWnd);
		INT32 getMemryUsage(HWND hWnd);
		INT32 getCPULoad(HWND hWnd);
		INT32 getGPUUsage(HWND hWnd);
	}
	
	// Raster graphics definitions
	namespace Raster {
		
	}

	// Vector graphics definitions
	namespace Vector {
		typedef struct {
			INT32 x;
			INT32 y;
		} Point, *pPoint;
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_GRAPHICS_HH */