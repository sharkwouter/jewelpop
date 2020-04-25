//
// Created by wouter on 4/25/20.
//

#ifndef BREAKDOWN_BOARD_HPP
#define BREAKDOWN_BOARD_HPP

#include <SDL2/SDL.h>
#include "window.h"
#include "rect.h"

class Board {
public:
    Board(int blockSize, int width, int height, int offset_x, int offset_y);
    ~Board();

    void draw();

private:
    int _blockSize;
    int _width;
    int _height;

    int _offset_x;
    int _offset_y;
    int _end_x;
    int _end_y;

    Rect *_selectionBox = nullptr;
};


#endif //BREAKDOWN_BOARD_HPP
