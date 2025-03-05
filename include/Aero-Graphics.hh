#ifndef AERO_GRAPHICS_HH
#define AERO_GRAPHICS_HH

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <Winuser.h>
#include <winnt.h>

namespace Aero_Graphics {
	namespace Util {
		UINT getFPS();
	}

	namespace Entity {
		
	}

	namespace Render {
		PVOID Block(PBYTE lpTexture);
		PBYTE Texture();
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_GRAPHICS_HH */