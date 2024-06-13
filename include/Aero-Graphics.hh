#ifndef AERO_GRAPHICS_HH
#define AERO_GRAPHICS_HH

#include <basetsd.h>

#include <Windows.h>
#include <WinUser.h>
#include <WinBase.h>

#include <minwindef.h>

enum Aero_Win_State{
	AERO_BORDERLESS,
	AERO_MIN,
	AERO_MAX
};

namespace Aero_Graphics {
	void Window(
		INT32 Height, INT32 Width,
		FLOAT POSX, FLOAT POSY,
		Aero_Win_State WinState,
		void *Render
	);

	void Window_Render(
		INT32 Height, INT32 Width,
		FLOAT POSX, FLOAT POSY,
		Aero_Win_State WinState
	);

	namespace Win_Component {
		PINT32 Button();
		PINT32 Cursor();
		PINT32 Menu();
	}
}


#endif /* AERO_GRAPHICS_HH */