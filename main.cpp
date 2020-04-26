#include "constants.hpp"
#include "window.hpp"
#include "board.hpp"

#define GAME "Jewelpop"

#ifdef __PSP__
#include <pspkernel.h>
PSP_MODULE_INFO(GAME, 0, 1, 1);
#endif

void handleEvents(Window &window, Board &board) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        window.handleEvents(event);
        board.handleEvents(event);
    }
}

int main(int argc, char const *argv[])
{
    Window window(GAME, Constants::screen_width, Constants::screen_height);
    Board board = Board();

    //Main loop
    while (!window.isClosed())
    {
        handleEvents(window, board);
        board.draw();
        window.clear();
    }
    
    return 0;
}
