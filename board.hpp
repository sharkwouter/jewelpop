//
// Created by wouter on 4/25/20.
//

#ifndef JEWELPOP_BOARD_HPP
#define JEWELPOP_BOARD_HPP

#include <SDL2/SDL.h>
#include "constants.hpp"
#include "window.hpp"
#include "jewels.hpp"

class Board {
public:
    Board();
    ~Board();

    void draw();
    void setBoardMeasurements();
    void handleEvents(SDL_Event &event);

private:
    void fillBoard();
    void move_selection(int x, int y);

private:
    int _end_x;
    int _end_y;

    int _board[Constants::board_width][Constants::board_height];

    int _selection_x = 3;
    int _selection_y = 3;

    SDL_Rect _selectionBox;
};


#endif //JEWELPOP_BOARD_HPP
