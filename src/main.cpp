#include <SDL2/SDL.h>
#include "constants.hpp"
#include "window.hpp"
#include "board.hpp"



void handleEvents(Window &window, Board &board) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        window.handleEvents(event);
        board.handleEvents(event);
    }
}

int gameLoop(int argc, char *argv[]) {
    Window window(GAME, Constants::screen_width, Constants::screen_height);
    Board board = Board();

    //Main loop
    while (!window.isClosed()) {
        handleEvents(window, board);
        board.draw();
        window.clear();
    }
    return 0;
}

#ifdef __PSP__
extern "C"
{
    int SDL_main(int argc, char *argv[]) {
        return gameLoop(argc, argv);
    }
}
#else
int main(int argc, char *argv[]) {
    return gameLoop(argc, argv);
}
#endif