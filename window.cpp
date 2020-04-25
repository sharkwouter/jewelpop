#include "window.h"

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
    _closed = !init();
}

Window::~Window() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(1, "Failed to initialize initialize SDL. Error: %s", SDL_GetError());
        return false;
    }

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _width,
        _height,
        0
    );

    if (_window == nullptr) {
        SDL_LogError(1, "Failed to initiation window. Error %s", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) {
        SDL_LogError(1, "Failed to initialize renderer. Error: %s", SDL_GetError());
        return false;
    }

    return true;
}


void Window::handleEvents() {
    if (SDL_PollEvent(&_event)) {
        switch (_event.type) {
            case SDL_QUIT:
                _closed = true;
                break;
        }
    }
}

void Window::draw() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
    SDL_RenderClear(_renderer);

    SDL_Rect rect;
    rect.w = 120;
    rect.h = 120;
    rect.x = 400;
    rect.y = 300;
    SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
    SDL_RenderFillRect(_renderer, &rect);

    SDL_RenderPresent(_renderer);
}