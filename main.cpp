#include "window.h"
#include "rect.h"
#include "board.hpp"

#define GAME "test"

#ifdef __PSP__
#include <pspkernel.h>
PSP_MODULE_INFO(GAME, 0, 1, 1);
#endif



void handleEvents(Window &window) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        window.handleEvents(event);
    }
}

int main(int argc, char const *argv[])
{
    int screen_width = 480;
    int screen_height = 272;
    int board_width = 8;
    int board_height = 7;
    int blockSize = screen_height/board_height;
    int offset_y = (screen_height-(blockSize*board_height))/2;
    int offset_x = offset_y;


    Window window(GAME, screen_width, screen_height);
    Board board(blockSize, board_width, board_height, offset_x, offset_y);

    //Main loop
    while (!window.isClosed())
    {
        handleEvents(window);
        board.draw();
        window.clear();
    }
    
    return 0;
}
