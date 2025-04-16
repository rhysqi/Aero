#include <Windows.h>
#include <wingdi.h>

#include <CL/cl.h>

#include <gl/GL.h>
#include <gl/GLU.h>

#include <stdio.h>
#include <string.h>

LRESULT CALLBACK DummyWndProc(HWND, UINT, WPARAM, LPARAM);

// Dummy Window untuk buat OpenGL context
HGLRC createDummyGLContext(HDC* hdc) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = DummyWndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "DummyGLWindow";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, "Dummy", WS_OVERLAPPEDWINDOW, 
                             CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                             NULL, NULL, wc.hInstance, NULL);

    *hdc = GetDC(hwnd);
    
    PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1, 
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, 
        PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        24, 8, 0, PFD_MAIN_PLANE, 0, 0, 0, 0 };

    int pf = ChoosePixelFormat(*hdc, &pfd);
    SetPixelFormat(*hdc, pf, &pfd);

    HGLRC hglrc = wglCreateContext(*hdc);
    wglMakeCurrent(*hdc, hglrc);

    return hglrc;
}

void destroyDummyGLContext(HDC hdc, HGLRC hglrc) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(NULL, hdc);
}

// Callback Dummy Window
LRESULT CALLBACK DummyWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    return DefWindowProc(hwnd, msg, wp, lp);
}

void checkOpenGLInterop() {
    cl_uint numPlatforms;
    cl_platform_id platforms[10];

    clGetPlatformIDs(10, platforms, &numPlatforms);
    printf("Found %d OpenCL platforms.\n", numPlatforms);

    // Buat dummy OpenGL context
    HDC hdc;
    HGLRC hglrc = createDummyGLContext(&hdc);

    for (cl_uint i = 0; i < numPlatforms; i++) {
        char platformName[256];
        clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(platformName), platformName, NULL);
        printf("\nPlatform: %s\n", platformName);

        cl_uint numDevices;
        cl_device_id devices[10];

        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, 10, devices, &numDevices);
        printf("  Found %d GPU devices.\n", numDevices);

        for (cl_uint j = 0; j < numDevices; j++) {
            char deviceName[256];
            clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL);
            printf("  - Device: %s\n", deviceName);

            char extensions[1024];
            clGetDeviceInfo(devices[j], CL_DEVICE_EXTENSIONS, sizeof(extensions), extensions, NULL);

            if (strstr(extensions, "cl_khr_gl_sharing")) {
                printf("    -> Supports OpenGL Interop (cl_khr_gl_sharing)\n");

                // Ambil versi OpenGL
                const char* glVersion = (const char*)glGetString(GL_VERSION);
                const char* glVendor = (const char*)glGetString(GL_VENDOR);
                printf("    -> OpenGL Version: %s\n", glVersion);
                printf("    -> OpenGL Vendor: %s\n", glVendor);
            } else {
                printf("    -> No OpenGL Interop Support\n");
            }
        }
    }

    // Hapus dummy OpenGL context
    destroyDummyGLContext(hdc, hglrc);
}

int main() {
    checkOpenGLInterop();
	
    return 0;
}
