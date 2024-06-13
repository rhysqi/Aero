#ifndef AERO_RENDER_ENGINE_HH
#define AERO_RENDER_ENGINE_HH

#include <Windows.h>
#include <WinUser.h>
#include <WinBase.h>

namespace Aero_Render_Engine {
	namespace Direct3D {
		void Init();
		int Process();
	}

	namespace GL {
		void Init();
		int Process();
	}

	namespace Vulkan {
		void Init();
		int Process();
	}
}

#endif /* AERO_RENDER_ENGINE_HH */