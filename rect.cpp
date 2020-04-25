//
// Created by wouter on 4/25/20.
//

#include "rect.hpp"

Rect::Rect(int x, int y, int width, int height, SDL_Color color) :
 _color(color)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = width;
    _rect.h = height;
}

Rect::~Rect() {
}

void Rect::handleEvents(SDL_Event &event) {
    if (event.type != SDL_KEYDOWN) {
        return;
    }
    int step = _rect.w;
    switch (event.key.keysym.sym) {
        case SDLK_UP:
            _rect.y -= step;
            break;
        case SDLK_DOWN:
            _rect.y += step;
            break;
        case SDLK_LEFT:
            _rect.x -= step;
            break;
        case SDLK_RIGHT:
            _rect.x += step;
            break;

    }
}

void Rect::draw() const {
    SDL_SetRenderDrawColor(Window::renderer, _color.r, _color.g, _color.b, _color.a);
    SDL_RenderFillRect(Window::renderer, &_rect);
}

Rect::Rect() {

}
