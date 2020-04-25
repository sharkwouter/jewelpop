#include "window.h"
#include "rect.h"

#define GAME "test"

#ifdef __PSP__
#include <pspkernel.h>
PSP_MODULE_INFO(GAME, 0, 1, 1);
#endif



void handleEvents(Window &window, Rect &rect) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        rect.handleEvents(event);
        window.handleEvents(event);
    }
}

int main(int argc, char const *argv[])
{
    Window window(GAME, 480, 272);
    Rect rect(window, 100, 100, 50, 50, SDL_Color{255, 0,0, 255});
    while (!window.isClosed())
    {
        handleEvents(window, rect);
        rect.draw();
        window.clear();
    }
    
    return 0;
}
