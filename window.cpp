#include "window.hpp"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
    _closed = !init();
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Window::init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize initialize SDL. Error: %s", SDL_GetError());
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
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initiation window. Error %s", SDL_GetError());
        return false;
    }

    Window::renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize renderer. Error: %s", SDL_GetError());
        return false;
    }

    return true;
}


void Window::handleEvents(SDL_Event &event) {
    switch (event.type) {
        case SDL_QUIT:
            _closed = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _closed = true;
                    break;
            }
            break;
    }
}

void Window::clear() {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, _backgoundColor.r, _backgoundColor.g, _backgoundColor.b, _backgoundColor.a);
    SDL_RenderClear(renderer);
}