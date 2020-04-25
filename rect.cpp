//
// Created by wouter on 4/25/20.
//

#include "rect.h"

Rect::Rect(const Window &window, int x, int y, int width, int height, SDL_Color color) :
Window(window), _color(color)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = width;
    _rect.h = height;
}

Rect::~Rect() {
}

void Rect::draw() const {
    SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
    SDL_RenderFillRect(_renderer, &_rect);
}
