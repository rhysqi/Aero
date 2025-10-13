
#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/X.h>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[]){

    Display* display = XOpenDisplay(NULL);
    int scr = DefaultScreen(display);

    printf(
        "Screen Height: %d\n", DisplayWidth(display, scr)
    );
    
    
    return 0;
}