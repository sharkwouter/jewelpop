//
// Created by wouter on 4/25/20.
//

#include "board.hpp"

Board::Board(int blockSize, int width, int height, int offset_x, int offset_y) :
_width(width), _height(height), _blockSize(blockSize), _offset_x(offset_x), _offset_y(offset_y), _end_x(offset_x + (blockSize * width)), _end_y(offset_y + (blockSize * height)){
}

Board::~Board() {

}

void Board::draw() {
    SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
    for (int x = 0; x <= _width; x++) {
        int current_x = _offset_x + x*_blockSize;
        SDL_RenderDrawLine(
                Window::renderer,
                current_x,
                _offset_y,
                current_x,
                _end_y
                );
    }
    for (int y = 0; y <= _height; y++) {
        int current_y = _offset_y + y*_blockSize;
        SDL_RenderDrawLine(
                Window::renderer,
                _offset_x,
                current_y,
                _end_x,
                current_y
        );
    }
}