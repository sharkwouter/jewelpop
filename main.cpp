#include "window.h"

#define GAME "test"

int main(int argc, char const *argv[])
{
    Window window("SDL", 800, 600);
    while (!window.isClosed())
    {
        window.handleEvents();
        window.draw();
    }
    
    return 0;
}
