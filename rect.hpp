//
// Created by wouter on 4/25/20.
//

#ifndef BREAKDOWN_RECT_H
#define BREAKDOWN_RECT_H

#include <SDL2/SDL.h>
#include "window.hpp"

class Rect{
public:
    Rect();
    Rect(int x, int y, int width, int height, SDL_Color color);
    ~Rect();
    void draw() const;
    void handleEvents(SDL_Event &event);

private:
    SDL_Color _color;
    SDL_Rect _rect;
};


#endif //BREAKDOWN_RECT_H
