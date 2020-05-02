#include "window.hpp"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
    _closed = !init();
}

Window::~Window() {
    if(_joystick != nullptr) {
        SDL_JoystickClose(_joystick);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Window::init() {
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
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

#ifdef __PSP__
    if (SDL_NumJoysticks() > 0) {
        _joystick = SDL_JoystickOpen(0);
    }
#endif

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
    SDL_SetRenderDrawColor(renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderClear(renderer);
}