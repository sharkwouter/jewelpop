#include "window.h"
#include "rect.h"

#define GAME "test"


int main(int argc, char const *argv[])
{
    Window window(GAME, 800, 600);
    Rect rect(window, 120, 120, 50, 50, SDL_Color{255, 0,0, 255});
    while (!window.isClosed())
    {
        window.handleEvents();
        rect.draw();
        window.clear();
    }
    
    return 0;
}
