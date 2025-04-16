#ifndef INPUT_HANDLING_HH
#define INPUT_HANDLING_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winuser.h>

#define VK_K_A 0x41
#define VK_K_B 0x42
#define VK_K_C 0x43
#define VK_K_D 0x44
#define VK_K_E 0x45
#define VK_K_F 0x46
#define VK_K_G 0x47
#define VK_K_H 0x48
#define VK_K_I 0x49
#define VK_K_J 0x4A
#define VK_K_K 0x4B
#define VK_K_L 0x4C
#define VK_K_M 0x4D
#define VK_K_N 0x4E
#define VK_K_O 0x4F
#define VK_K_P 0x50
#define VK_K_Q 0x51
#define VK_K_R 0x52
#define VK_K_S 0x53
#define VK_K_T 0x54
#define VK_K_U 0x55
#define VK_K_V 0x56
#define VK_K_W 0x57
#define VK_K_X 0x58
#define VK_K_Y 0x59
#define VK_K_Z 0x5A

#define VK_K_ESCAPE VK_ESCAPE
#define VK_K_SPACE VK_SPACE
#define VK_K_LCTRL VK_LCONTROL
#define VK_K_RCTRL VK_RCONTROL
#define VK_K_LSHIFT VK_LSHIFT
#define VK_K_RSHIFT VK_RSHIFT
#define VK_K_LALT VK_LMENU
#define VK_K_RALT VK_RMENU

typedef struct Mouse_Event {
	INT PosX;
	INT PosY;
	UINT Button;

	BOOL Keydown;
	BOOL Keyup;
	BOOL Keypress;
} Mouse_Event;

typedef struct Keyboard_Event {
	UINT KeyCode;
	
	BOOL Keydown;
	BOOL Keyup;
	BOOL Keypress;
} Keyboard_Event;

// Mouse_Event functions
HANDLE Mouse_Pointer_Position(HWND hWnd, Mouse_Event MouseEvent);
BOOL Mouse_Click(HWND hWnd, Mouse_Event MouseEvent);

// Keyboard_Event functions
BOOL Keyboard_Action(HWND hWnd, Keyboard_Event KeyEvent);
BOOL Keyboard_Accelerator(HWND hWnd, Keyboard_Event KeyEvent);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* INPUT_HANDLING_HH */