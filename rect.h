//
// Created by wouter on 4/25/20.
//

#ifndef BREAKDOWN_RECT_H
#define BREAKDOWN_RECT_H

#include <SDL2/SDL.h>
#include "window.h"

class Rect : public Window {
public:
    Rect(const Window &window, int x, int y, int width, int height, SDL_Color color);
    ~Rect();
    void draw() const;

private:
    int _x;
    int _y;
    int _width;
    int _height;
    SDL_Color _color;
    SDL_Rect _rect;

};


#endif //BREAKDOWN_RECT_H
